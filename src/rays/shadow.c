/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:05:16 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 20:05:16 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	t_vec3d	dummy[2];

	dist = vec_norm(ray.direction);
	unit_vector(ray.direction, ray.direction);
	while (obj)
	{
		t = intersect_dist(&ray, dummy, (t_object *)obj->content);
		if (isgreater(t, FLT_EPSILON) && isless(t, dist))
			return (-1);
		obj = obj->next;
	}
	return (1);
}

double	diffuse_shade(t_intersect *intersect, t_line ray)
{
	double	angle;

	unit_vector(ray.direction, ray.direction);
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
