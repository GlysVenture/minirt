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
	dist = intersect_objects(ray, *v->obj, &intersect);
	if (isless(dist, 0))
		return (0);
	return (shade(intersect, dist, ray, v));
/*	t = shadow_ray(temp, light, start, normal);
	if (isless(t, 0))
		return (0);
	else
		return (shift_color2(color,(t / M_PI_2 - 1)));*/
}

static int shade(t_object *intersect, double d, t_line *ray, t_vars *v)
{
	int 	color;
	(void)d;
	(void)ray;
//	int		is_diffuse;
//	t_vec3d	hit;

	color = shift_color2(intersect->color,v->ambient.ratio);
/*
	unit_vector2(ray->direction, &hit);
	scalar_mult2(hit, d, &hit);
	vec_sum(hit, ray->point, &hit);

	is_diffuse = diffuse_shade();
	color += kd * is_diffuse; //todo shifts
	if (is_diffuse > 0)
		color += ks * specular_shade();*/
	return (color);
}

/*int	diffuse_shade(t_object *intersect, t_vec3d hit, t_line *ray, t_vars *v)
{
	double	angle;
	t_vec3d	normal;

	vec_get_normal(intersect->type, intersect->structure, hit, &normal); // todo once
	angle = shadow_ray(hit, v, normal); //todo all goes trough v
}*/
