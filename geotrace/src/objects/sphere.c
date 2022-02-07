/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:37 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:37 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 22.01.22.
//

#include <math.h>
#include <stdlib.h>
#include <float.h>

#include "geotrace.h"

/// Creates a new sphere
/// \param radius
/// \param cx center x
/// \param cy center y
/// \param cz center z
/// \return memory allocated [t_sphere*] sphere
t_sphere	*init_sphere(double radius, double cx, double cy, double cz)
{
	t_sphere	*new;

	new = malloc(sizeof(t_sphere));
	if (!new)
		return (NULL);
	new->center[0] = cx;
	new->center[1] = cy;
	new->center[2] = cz;
	new->radius = radius;
	return (new);
}

/// Computes if a sphere intersects a certain ray and returns the closest
/// intersect distance. If it doesnt returns -1
/// \param sphere
/// \param ray
/// \return distance to intersection or -1 for no intersection
double	sphere_intersect(t_sphere *sphere, t_line ray)
{
	double	res[2];
	double	quad[2];

	vec_subtract(ray.point, sphere->center, ray.point);
	quad[0] = dot_prod(ray.point, ray.point)
		- pow(sphere->radius, 2);
	quad[1] = dot_prod(ray.point, ray.direction) * 2;
	solve_quad(quad, res);
	return (res[0]);
}

/// Computes if a sphere intersects a certain ray and returns the closest
/// intersect distance. If it doesnt returns -1. sets hit and normal
/// \warning hit is vector from ray.point to hitpoint on item. normal
/// not transformed yet. these should be dealt with when object
/// is known to be the one
/// \param sphere
/// \param ray
/// \param hit return hit point
/// \param normal return normal to object hit point
/// \return distance to intersection or -1 for no intersection
double	sphere_intersect2(t_object *sphere, t_line ray,
		t_vec3d hit, t_vec3d normal)
{
	double	res[2];
	double	quad[2];

	transform_ray(sphere->inv, sphere->tr_vec, &ray);
	quad[0] = dot_prod(ray.point, ray.point) - 1;
	quad[1] = dot_prod(ray.point, ray.direction) * 2;
	solve_quad(quad, res);
	if (isless(res[0], 0))
		return (-1);
	scalar_mult(ray.direction, res[0], hit);
	vec_sum(hit, ray.point, normal);
	matrix_vect_prod(sphere->transformation, hit, hit);
	if (isless(get_angle(normal, ray.direction), M_PI_2))
		scalar_mult(normal, -1, normal);
	return (vec_norm(hit));
}
