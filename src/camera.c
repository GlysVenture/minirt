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

#include "camera.h"
#include "geotrace.h"

void	set_advanced_camera(t_adv_camera	*cam, int x, int y, t_line *ray)
{
	double			tmp;
	t_vec3d			v;

	set_vec2(cam->horizontal, cam->cam.direction);
	cam->horizontal[2] = 0;
	tmp = cam->horizontal[0];
	cam->horizontal[0] = -cam->horizontal[1];
	cam->horizontal[1] = tmp;
	tmp = vec_norm(cam->cam.direction) * tan(cam->cam.angle / 2);
	unit_vector(cam->horizontal, cam->horizontal);
	scalar_mult(cam->horizontal, tmp / (x - 1), cam->horizontal);
	vec_prod(cam->cam.direction, cam->horizontal, cam->vertical);
	unit_vector(cam->vertical, cam->vertical);
	scalar_mult(cam->vertical, -tmp / (y - 1), cam->vertical);
	set_vec2(ray->point, cam->cam.origin);
	scalar_mult(cam->horizontal, (double)(x - 1) / -2, v);
	vec_sum(cam->cam.direction, v, ray->direction);
	scalar_mult(cam->vertical, (double)(y - 1) / -2, v);
	vec_sum(ray->direction, v, ray->direction);
}
