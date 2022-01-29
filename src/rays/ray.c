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

double	intersect_objects(t_line *ray, t_list *obj, t_object *found)
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
			t = sphere_intersect(((t_object *)obj->content)->structure, *ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, *ray);
		if (isgreater(t, FLT_EPSILON) && (dist < 0 || isless(t, dist)))
		{
			dist = t;
			*found = *(t_object *)obj->content;
		}
		obj = obj->next;
	}
	return (dist);
}

int	send_ray(t_line *ray, t_vars *v)
{
	t_intersect	intersect;

	intersect.in_ray = *ray; //todo set to unit ?
	intersect.dist = intersect_objects(ray, v->obj, &(intersect.obj));
	if (isless(intersect.dist, 0))
		return (0);
	return (shade(&intersect, v));
}

/*static int shade(t_intersect *intersect, t_vars *v)
{
	int		color;
	t_list	*pos;
	t_line	s_ray;

	unit_vector2(intersect->in_ray.direction, &intersect->hit);
	scalar_mult2(intersect->hit, intersect->dist, &intersect->hit);
	vec_sum(intersect->hit, intersect->in_ray.point, &intersect->hit);
	vec_get_normal(intersect->obj.type, intersect->obj.structure, intersect->hit, &intersect->normal);

	pos = v->lights;
	while (pos)
	{
		color = shift_color2(intersect->obj.color, v->ambient.color, v->ambient.ratio);
		s_ray.point = intersect->hit;
		vec_subtract(((t_light *)pos->content)->pos, intersect->hit, &s_ray.direction);
		if (shadow_ray(&s_ray, v->obj) > 0) //todo multiple?
		{
			color = shift_color(color, intersect->obj.color, diffuse_shade(intersect, &s_ray));
			color = shift_color(color, ((t_light *)pos->content)->color, specular_shade(intersect, &s_ray));
//			sum += 0.4;
//			color = shift_color2(color, ((t_light *)pos->content)->color, 1);
		}
		pos = pos->next;
	}
	return (color);
}*/

static int shade(t_intersect *intersect, t_vars *v)
{
	t_list	*pos;
	t_line	s_ray;
	double	color[3];
	double	ref_light[3];

	unit_vector(intersect->in_ray.direction, intersect->hit);
	scalar_mult(intersect->hit, intersect->dist, intersect->hit);
	vec_sum(intersect->hit, intersect->in_ray.point, intersect->hit);

	vec_get_normal(intersect);

	unpack_color(color, 0, 0);
	unpack_color(intersect->diff_l, intersect->obj.color, 0.7);
	unpack_color(intersect->spec_l, 0xFFFFFF, 0.5);
	pos = v->lights;
	while (pos)
	{
		unpack_color(ref_light, intersect->obj.color, 0.1);

		set_vec2(s_ray.point, intersect->hit);
		vec_subtract(((t_light *)pos->content)->pos, intersect->hit, s_ray.direction);
		if (shadow_ray(&s_ray, v->obj) > 0) //todo multiple?
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
