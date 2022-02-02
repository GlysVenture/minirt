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

int	shadow_ray(t_line ray, t_list *obj)
{
	double	dist;
	double	t;
	char	obj_type;
	t_vec3d	h, n;

	dist = vec_norm(ray.direction);
	unit_vector(ray.direction, ray.direction);
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect2((t_object *)obj->content, ray, h, n); // todo fix with other intersect
		if (obj_type == 'p')
			t = plane_intersect2((t_object *)obj->content, ray, h, n);
		if (obj_type == '#')
			t = cube_intersect2((t_object *)obj->content, ray, h, n);
		if (obj_type == 'c')
			t = cylinder_intersect2((t_object *)obj->content, ray, h, n);
		if (isgreater(t, FLT_EPSILON) && isless(t, dist))
			return (-1);
		obj = obj->next;
	}
	return (1);
}

double	diffuse_shade(t_intersect *intersect, t_line ray)
{
	double	angle;

	angle = cos_angle(intersect->normal, ray.direction);
	if (isless(angle, 0))
		return (0);
	return (angle);
}

double	specular_shade(t_intersect *intersect, t_line ray)
{
	double	angle;
	t_vec3d	mid;

	unit_vector(ray.direction, ray.direction);
	vec_subtract(ray.direction, intersect->in_ray.direction, mid);
	angle = cos_angle(intersect->normal, mid);
	if (isless(angle, 0))
		angle = 0;
	return (pow(angle, 20));
}
