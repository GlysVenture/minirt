//
// Created by tkondrac on 23.01.22.
//

#include <stdlib.h>

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

/// Computes if a plane intersects a certain ray and returns the distance. If it doesnt returns -1
/// \param plane
/// \param ray
/// \return distance to plane intersect or -1 if parallel
double	plane_intersect(t_plane *plane, t_line ray)
{
	double	angle;

	vec_subtract(plane->point, ray.point, ray.point);
	unit_vector(ray.direction, ray.direction);
	angle = dot_prod(plane->normal, ray.direction);
	if (angle == 0)
		return (-1);
	return (dot_prod(plane->normal, ray.point) / angle);
}