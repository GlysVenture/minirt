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

static int shade(t_object *intersect, double d, t_line *ray, t_vars *v);

double	intersect_objects(t_line *ray, t_list *obj, t_object **found)
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
			if (found)
				*found = (t_object *)obj->content;
		}
		obj = obj->next;
	}
	return (dist);
}

int	send_ray(t_line *ray, t_vars *v)
{
//	t_light	light = {{3, -2, 4}, 0x00FFFFFF};
	t_object	*intersect;
	double	dist;

	intersect = NULL;
	dist = intersect_objects(ray, v->obj, &intersect);
	if (isless(dist, 0))
		return (0);
	return (shade(intersect, dist, ray, v));
}

static int shade(t_object *intersect, double d, t_line *ray, t_vars *v)
{
	int	color;
	double	sum;
//	t_list	*pos;
	t_vec3d	hit;

	unit_vector2(ray->direction, &hit);
	scalar_mult2(hit, d, &hit);
	vec_sum(hit, ray->point, &hit);

	sum = 0;
	color = intersect->color;
	color = shift_color2(color, v->ambient.color, v->ambient.ratio * 0.2);
//	color *= 0.2 * v->ambient.ratio * ((double)v->ambient.color) / 255;
	sum += 0.2;

//	pos = v->lights;
//	while (pos)
//	{
//		if (shadow_ray(hit, *(t_light *)pos->content, v->obj)) //todo multiple?
//		{
//			color += diffuse_shade();
//			color += specular_shade();
//			sum += 0.7 + 0.4;
//		}
//	}

	color = color / sum;
	return (color);
}
