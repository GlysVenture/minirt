//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include <math.h>
#include <stdio.h>
#include <float.h>

#include "light.h"
#include "libft.h"
#include "../object.h"

#include "../debug/debug.h"

double	shadow_ray(t_vec3d start, t_light light, t_list *obj, t_vec3d n)
{
	double	dist;
	double	t;
	t_line	ray;
	char	obj_type;

	ray.point = start;
	vec_subtract(light.pos, start, &ray.direction);
	dist = -1;
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, ray);
		if (isgreater(t, FLT_EPSILON) && (isless(dist, 0) || isless(t, dist)))
			dist = t;
		obj = obj->next;
	}
	if (isgreater(dist, 0) && isless(dist, vec_norm(ray.direction)))
		return (-1);
	return (get_angle(ray.direction, n));
}
