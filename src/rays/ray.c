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
	t_vec3d	data[2];

	dist = -1;
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect2(((t_object *)obj->content), ray, data[0], data[1]);
		if (obj_type == 'p')
			t = plane_intersect2(((t_object *)obj->content), ray, data[0], data[1]);
		if (obj_type == '#')
			t = cube_intersect2(((t_object *)obj->content), ray, data[0], data[1]);
		if (obj_type == 'c')
			t = cylinder_intersect2(((t_object *)obj->content), ray, data[0], data[1]);
		if (isgreater(t, FLT_EPSILON) && (dist < 0 || isless(t, dist)))
		{
			dist = t;
			set_vec2(intersect->hit, data[0]);
			set_vec2(intersect->normal, data[1]);
			intersect->obj = *(t_object *)obj->content; //todo pass by pointer?
		}
		obj = obj->next;
	}
	return (dist);
}

int	send_ray(t_line *ray, t_vars *v)
{
	t_intersect	intersect;

	intersect.in_ray = *ray;
	unit_vector(intersect.in_ray.direction, intersect.in_ray.direction);
	intersect.dist = intersect_objects(intersect.in_ray, v->obj, &intersect);
	if (isless(intersect.dist, 0))
		return (0);
	vec_sum(intersect.hit, intersect.in_ray.point, intersect.hit);
	matrix_vect_prod(intersect.obj.inv_transp, intersect.normal, intersect.normal);

//	return (intersect.obj.colors[0]);
	return (shade(&intersect, v));
}

static int shade(t_intersect *intersect, t_vars *v)
{
	t_list	*pos;
	t_line	s_ray;
	double	color[3];
	double	ref_light[3];

	unpack_color(color, 0, 0);
	unpack_color(intersect->diff_l, intersect->obj.colors[0], intersect->obj.k_ratio[1]);
	unpack_color(intersect->spec_l, intersect->obj.colors[1], intersect->obj.k_ratio[2]);
	pos = v->lights;
	while (pos)
	{
		unpack_color(ref_light, intersect->obj.colors[0], intersect->obj.k_ratio[0]);
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
