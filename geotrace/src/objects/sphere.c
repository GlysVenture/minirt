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
	new->center.x = cx;
	new->center.y = cy;
	new->center.z = cz;
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
	double 	res[2];
	double	quad[2];
	double	delta;

	vec_subtract(ray.point, sphere->center, &ray.point);
	unit_vector2(ray.direction, &ray.direction); // todo all rays have unit vectors better sol
	quad[0] = dot_prod(ray.point, ray.point) - pow(sphere->radius, 2);
	quad[1] = dot_prod(ray.point, ray.direction) * 2;
	delta = pow(quad[1], 2) - 4 * quad[0] * 1;
	if (isless(delta, FLT_EPSILON))
		return (-1);
	if (fabs(delta) <= FLT_EPSILON)
		res[0] = - quad[1] / 2;
	else
	{
		res[0] = (sqrt(delta) - quad[1]) / 2;
		res[1] = - (sqrt(delta) + quad[1]) / 2;
		if (isgreaterequal(res[1], FLT_EPSILON) && isgreaterequal(res[0], FLT_EPSILON) && isless(res[1], res[0]))
			res[0] = res[1];
	}
	return (res[0]);
}
