/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:36 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:36 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 2/2/22.
//

#include <math.h>

#include "cylinder.h"
#include "geotrace.h"

double	plane_int0(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal)
{
	scalar_mult(ray.direction, -ray.point[2] / ray.direction[2], hit);
	matrix_vect_prod(cyl->transformation, hit, hit);
	set_vec(normal, 0, 0, 1);
	if (isless(get_angle(normal, ray.direction), M_PI_2))
		scalar_mult(normal, -1, normal);
	if (signbit(-ray.point[2] / ray.direction[2]))
		return (-vec_norm(hit));
	return (vec_norm(hit));
}

double	plane_int1(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal)
{
	ray.point[2] -= 1;
	scalar_mult(ray.direction, -ray.point[2] / ray.direction[2], hit);
	matrix_vect_prod(cyl->transformation, hit, hit);
	set_vec(normal, 0, 0, 1);
	if (isless(get_angle(normal, ray.direction), M_PI_2))
		scalar_mult(normal, -1, normal);
	if (signbit(-ray.point[2] / ray.direction[2]))
		return (-vec_norm(hit));
	return (vec_norm(hit));
}
