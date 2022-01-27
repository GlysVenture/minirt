//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include <math.h>
#include <float.h>
#include <stdio.h>

#include "ray.h"
#include "object.h"
#include "minirt.h"
#include "vec_utils.h"
#include "colors/colors.h"

#include "debug/debug.h"

int	shadow_ray(t_line *ray, t_list *obj)
{
	double	dist;
	double	t;
	char	obj_type;

	dist = vec_norm(ray->direction);
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, *ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, *ray);
		if (isgreater(t, FLT_EPSILON) && (isless(dist, 0) || isless(t, dist)))
			return (-1);
		obj = obj->next;
	}
	return (1);
}

double	diffuse_shade(t_intersect *intersect, t_line *ray)
{
	double	angle;

	angle = get_angle(intersect->normal, ray->direction);
	angle = (1 - (angle / M_PI_2));
	if (isless(angle, 0))
		return (0);
	return (angle);
}

double	specular_shade(t_intersect *intersect, t_line *ray)
{
	double	angle;
	t_vec3d	mid;

	vec_subtract(ray->direction, intersect->in_ray.direction, &mid);
	angle = get_angle(intersect->normal, mid);
	angle = (1 - angle / M_PI_2);
	if (isless(angle, 0))
		angle = 0;
	return ((double)pow(angle, 10));
}
