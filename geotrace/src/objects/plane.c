/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:37 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:37 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 23.01.22.
//

#include <stdlib.h>
#include <math.h>
#include <float.h>

#include "geotrace.h"

/// Creates a new plane from a normal vector and a point
/// \param normal vector
/// \param p any point of plane
/// \return memory allocated [t_plane*]
t_plane	*init_plane(t_vec3d normal, t_vec3d p)
{
	t_plane	*new;

	new = malloc(sizeof(t_plane));
	if (!new)
		return (NULL);
	set_vec(new->normal, normal[0], normal[1], normal[2]);
	set_vec(new->point, p[0], p[1], p[2]);
	return (new);
}

/// Computes if a plane intersects a certain ray and returns the distance.
/// If it doesnt returns -1
/// \param plane
/// \param ray
/// \return distance to plane intersect or -1 if parallel
double	plane_intersect(t_plane *plane, t_line ray)
{
	double	angle;

	vec_subtract(plane->point, ray.point, ray.point);
	angle = dot_prod(plane->normal, ray.direction);
	if (angle == 0)
		return (-1);
	return (dot_prod(plane->normal, ray.point) / angle);
}

/// Computes if a plane intersects a certain ray and returns the distance.
/// If it doesnt returns -1. sets hit and normal
/// \warning hit is vector from ray.point to hitpoint on item. normal
/// not transformed yet. these should be dealt with when object
/// is known to be the one
/// \param object plane
/// \param ray
/// \param hit return hit point
/// \param normal return normal to object hit point
/// \return distance to plane intersect or -1 if parallel
double	plane_intersect2(t_object *plane, t_line ray,
		t_vec3d hit, t_vec3d normal)
{
	transform_ray(plane->inv, plane->tr_vec, &ray);
	if (fabs(ray.direction[2]) <= FLT_EPSILON)
		return (-1);
	scalar_mult(ray.direction, -ray.point[2] / ray.direction[2], hit);
	matrix_vect_prod(plane->transformation, hit, hit);
	set_vec(normal, 0, 0, 1);
	if (isless(get_angle(normal, ray.direction), M_PI_2))
		scalar_mult(normal, -1, normal);
	if (isless(-ray.point[2] / ray.direction[2], 0))
		return (-vec_norm(hit));
	return (vec_norm(hit));
}
