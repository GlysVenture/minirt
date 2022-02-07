/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:05:15 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 20:05:15 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	shade(t_intersect *in, t_vars *v);

double	intersect_dist(t_line *ray, t_vec3d d[2], t_object *obj)
{
	if (obj->type == 's')
		return (sphere_intersect2(obj, *ray, d[0], d[1]));
	if (obj->type == 'p')
		return (plane_intersect2(obj, *ray, d[0], d[1]));
	if (obj->type == '#')
		return (cube_intersect2(obj, *ray, d[0], d[1]));
	if (obj->type == 'c')
		return (cylinder_intersect2(obj, *ray, d[0], d[1]));
	return (-2);
}

double	intersect_objects(t_line ray, t_list *obj, t_intersect *intersect)
{
	double	dist;
	double	t;
	t_vec3d	d[2];

	dist = -1;
	while (obj)
	{
		t = intersect_dist(&ray, d, ((t_object *)obj->content));
		if (isgreater(t, FLT_EPSILON) && (dist < 0 || isless(t, dist)))
		{
			dist = t;
			set_vec2(intersect->hit, d[0]);
			set_vec2(intersect->normal, d[1]);
			intersect->obj = *(t_object *)obj->content;
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
	matrix_vect_prod(intersect.obj.inv_transp,
		intersect.normal, intersect.normal);
	return (shade(&intersect, v));
}

void	ft_brdf(t_intersect *in, t_light light, t_vars *v, double color[3])
{
	double	ref_light[3];
	t_line	s_ray;

	unpack_color(ref_light, in->obj.colors[0],
		in->obj.k_ratio[0]);
	set_vec2(s_ray.point, in->hit);
	vec_subtract(light.pos, in->hit, s_ray.direction);
	if (shadow_ray(s_ray, v->obj) > 0)
	{
		color_sum2(ref_light, in->diff_l, diffuse_shade(in, s_ray));
		color_sum2(ref_light, in->spec_l, specular_shade(in, s_ray));
	}
	color_mult2(ref_light, light.color,
		150 * light.ratio / pow(vec_norm(s_ray.direction), 2));
	color_sum(color, ref_light);
	clamp(color, 0, 1);
}

static int	shade(t_intersect *in, t_vars *v)
{
	t_list	*pos;
	double	color[3];

	unpack_color(color, 0, 0);
	unpack_color(in->diff_l, in->obj.colors[0], in->obj.k_ratio[1]);
	unpack_color(in->spec_l, in->obj.colors[1], in->obj.k_ratio[2]);
	pos = v->lights;
	while (pos)
	{
		ft_brdf(in, *(t_light *)pos->content, v, color);
		pos = pos->next;
	}
	return (create_color(0, (int)(255 * color[0]),
		(int)(255 * color[1]), (int)(255 * color[2])));
}
