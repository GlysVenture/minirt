//
// Created by tkondrac on 30.01.22.
//

#include <math.h>

#include "geotrace.h"

static double	plane_int0(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal)
{
	scalar_mult(ray.direction, - ray.point[2] / ray.direction[2], hit);
	matrix_vect_prod(cyl->transformation, hit, hit);
	set_vec(normal, 1, 0, 0);
	return (vec_norm(hit));
}

static double	plane_int1(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal)
{
	ray.point[2] -= 1;
	scalar_mult(ray.direction, - ray.point[2] / ray.direction[2], hit);
	hit[2] += 1;
	matrix_vect_prod(cyl->transformation, hit, hit);
	set_vec(normal, 1, 0, 0);
	return (vec_norm(hit));
}

/// Computes if a closed cylinder intersects a certain ray and returns the closest
///// intersect distance. If it doesnt returns -1. sets hit and normal
/// \warning hit and normal is not translated back yet and normal might be wrong direction.
/// Both of those should be taken care of when intersected object
/// is known to be the one
/// \param cyl cylinder
/// \param ray
/// \param hit return hit point
/// \param normal return normal to object hit point
/// \return distance to intersection or -1 for no intersection
double	cylinder_intersect2(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal)
{
	double	res[2];
	double	quad[2];
	double	yc[2];

	transform_ray(cyl->inv, cyl->tr_vec, &ray);
	quad[0] = pow(ray.point[0], 2) + pow(ray.point[1], 2) - 1;
	quad[1] = 2 * ray.direction[0] * ray.point[0] + 2 * ray.direction[1] * ray.point[1];
	solve_quad(quad, res);
	if (isless(res[0], 0))
		return (-1);
	yc[0] = ray.point[2] + ray.direction[2] * res[0];
	yc[1] = ray.point[2] + ray.direction[2] * res[1];
	if (isgreater(yc[0], 1) && isgreater(yc[1], 1))
		return (-1);
	if (isless(yc[0], 0) && isless(yc[1], 0))
		return (-1);
	if (isgreater(yc[0], 1) && isless(yc[1], 1))
		return plane_int1(cyl, ray, hit, normal);
	if (isless(yc[0], 0) && isgreater(yc[1], 0))
		return plane_int0(cyl, ray, hit, normal);
	scalar_mult(ray.direction, res[0], hit);
	set_vec2(normal, hit);
	normal[2] = 0;
	matrix_vect_prod(cyl->transformation, hit, hit);
	return (vec_norm(hit));
}
