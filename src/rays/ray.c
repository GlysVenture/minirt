//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include <math.h>
#include <float.h>
#include <stdio.h>

#include "ray.h"
#include "geotrace.h"
#include "libft.h"
#include "../light/light.h"
#include "../object.h"
#include "../colors/colors.h"
#include "vec_utils.h"
#include "minirt.h"

#include "debug/debug.h"

static int shade(t_intersect *intersect, t_vars *v);

double	intersect_objects(t_line ray, t_list *obj, t_intersect *intersect)
{
	double	dist;
	double	t;
	char	obj_type;

	dist = -1;
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, ray);
		if (isgreater(t, FLT_EPSILON) && (dist < 0 || isless(t, dist)))
		{
			dist = t;
			intersect->obj = *(t_object *)obj->content; //todo pass by pointer?
		}
		obj = obj->next;
	}
	return (dist);
}

int	send_ray(t_line *ray, t_vars *v)
{
	t_intersect	intersect;
//	t_matrix a = {{1, 0, 0},{0, 1, 0},{0, 0, 2}};
//	t_matrix b, c;
//
//	inverse_matrix(a, c);
//	matrix_transpose(c, b);

	intersect.in_ray = *ray;
	unit_vector(intersect.in_ray.direction, intersect.in_ray.direction);
	intersect.dist = intersect_objects(intersect.in_ray, v->obj, &intersect);
	if (isless(intersect.dist, 0))
		return (0);

	scalar_mult(intersect.in_ray.direction, intersect.dist, intersect.hit);
	vec_sum(intersect.hit, intersect.in_ray.point, intersect.hit);

	vec_get_normal(&intersect);

	//return to world
//	if (intersect.obj.type == 's')
//	{
//		vec_sum(intersect.in_ray.point, intersect.hit, intersect.hit);
//		matrix_vect_prod(intersect.obj.inv_transpose, intersect.normal, intersect.normal);
//	}

//	return (intersect.obj.color);
	return (shade(&intersect, v));
}

static int shade(t_intersect *intersect, t_vars *v)
{
	t_list	*pos;
	t_line	s_ray;
	double	color[3];
	double	ref_light[3];

	unpack_color(color, 0, 0);
	unpack_color(intersect->diff_l, intersect->obj.color, 0.7);
	unpack_color(intersect->spec_l, 0xFFFFFF, 0.2);
	pos = v->lights;
	while (pos)
	{
		unpack_color(ref_light, intersect->obj.color, 0.05);

		set_vec2(s_ray.point, intersect->hit);
		vec_subtract(((t_light *)pos->content)->pos, intersect->hit, s_ray.direction);
		if (shadow_ray(s_ray, v->obj) > 0) //todo multiple?
		{
			color_sum2(ref_light, intersect->diff_l, diffuse_shade(intersect, s_ray));
			color_sum2(ref_light, intersect->spec_l, specular_shade(intersect, s_ray));
		}
		color_mult2(ref_light, ((t_light *)pos->content)->color, 150 * ((t_light *)pos->content)->ratio / pow(vec_norm(s_ray.direction), 2));
		color_sum(color, ref_light);
		clamp(color, 0, 1);
		pos = pos->next;
	}
	return (create_color(0, (int)(255 * color[0]), (int)(255 * color[1]), (int)(255 * color[2])));
}
