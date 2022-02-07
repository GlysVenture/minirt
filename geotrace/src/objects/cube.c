/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:35 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:35 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/31/22.
//

#include <math.h>
#include <float.h>

#include "geotrace.h"
#include "cube.h"

static void	upd_res(double res[], double temp[3][2], int n)
{
	res[0] = temp[n][0];
	res[1] = temp[n][1];
}

/// fills in 2 intersect points of 6 planes of a cube
/// \param ray
/// \param res
/// \return 1 if success, 0 if failure (parrallel and out of bounds)
static int	get_res(t_line *ray, double res[])
{
	double	temp[3][2];
	int		t[3];

	t[0] = get_x_int(temp[0], ray);
	t[1] = get_y_int(temp[1], ray);
	t[2] = get_z_int(temp[2], ray);
	if (!t[0] || !t[1] || !t[2])
		return (0);
	if (t[0] == -1)
	{
		if (t[1] == -1)
		{
			upd_res(res, temp, 2);
			return (1);
		}
		upd_res(res, temp, 1);
	}
	else
		upd_res(res, temp, 0);
	if (t[1] == 1)
		add_bounds(res, temp[1]);
	if (t[2] == 1)
		add_bounds(res, temp[2]);
	return (1);
}

static void	get_cube_normal(t_vec3d hit, t_vec3d normal)
{
	if (fabs(hit[0]) <= FLT_EPSILON || fabs(hit[0] - 1) <= FLT_EPSILON)
		set_vec(normal, 1, 0, 0);
	if (fabs(hit[1]) <= FLT_EPSILON || fabs(hit[1] - 1) <= FLT_EPSILON)
		set_vec(normal, 0, 1, 0);
	if (fabs(hit[2]) <= FLT_EPSILON || fabs(hit[2] - 1) <= FLT_EPSILON)
		set_vec(normal, 0, 0, 1);
}

/// Computes if a cube intersects a certain ray and returns the closest
///// intersect distance. If it doesnt returns -1. sets hit and normal
/// \warning hit is vector from ray.point to hitpoint on item. normal
/// not transformed yet. these should be dealt with when object
/// is known to be the one
/// \param cube cube
/// \param ray
/// \param hit return hit point
/// \param normal return normal to object hit point
/// \return distance to intersection or -1 for no intersection
double	cube_intersect2(t_object *cube, t_line ray, t_vec3d hit, t_vec3d normal)
{
	double	res[2];
	t_vec3d	temp;

	transform_ray(cube->inv, cube->tr_vec, &ray);
	if (!get_res(&ray, res) || isless(res[1], res[0]))
		return (-1);
	if (isgreater(res[1], 0) && isless(res[1], res[0]))
		swap(res, res + 1);
	if (isless(res[0], 0))
		return (-1);
	scalar_mult(ray.direction, res[0], hit);
	vec_sum(hit, ray.point, temp);
	get_cube_normal(temp, normal);
	matrix_vect_prod(cube->transformation, hit, hit);
	if (isless(get_angle(normal, ray.direction), M_PI_2))
		scalar_mult(normal, -1, normal);
	return (vec_norm(hit));
}
