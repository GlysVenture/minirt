/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:38:15 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:38:15 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/24/22.
//

#include <math.h>
#include <stdlib.h>
#include <float.h>

#include "camera.h"
#include "geotrace.h"

static int	is_vec_null(t_vec3d v)
{
	if (fabs(v[0]) <= FLT_EPSILON && fabs(v[1]) <= FLT_EPSILON
		&& fabs(v[2]) <= FLT_EPSILON)
		return (1);
	return (0);
}

void	set_advanced_camera(t_adv_camera	*cam, int x, int y, t_line *ray)
{
	double			tmp;
	t_vec3d			v;

	set_vec(v, 0, 0, 1);
	vec_prod(cam->cam.direction, v, cam->horizontal);
	if (is_vec_null(cam->horizontal))
		set_vec(cam->horizontal, 1, 0, 0);
	tmp = vec_norm(cam->cam.direction) * tan(cam->cam.angle / 2);
	unit_vector(cam->horizontal, cam->horizontal);
	scalar_mult(cam->horizontal, 2 * -tmp / x, cam->horizontal);
	vec_prod(cam->cam.direction, cam->horizontal, cam->vertical);
	unit_vector(cam->vertical, cam->vertical);
	scalar_mult(cam->vertical, 2 * -tmp / y, cam->vertical);
	set_vec2(ray->point, cam->cam.origin);
	scalar_mult(cam->horizontal, ((double)x) / -2, v);
	vec_sum(cam->cam.direction, v, ray->direction);
	scalar_mult(cam->vertical, ((double)y) / -2, v);
	vec_sum(ray->direction, v, ray->direction);
}
