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
	set_vec(&(new->normal), normal.x, normal.y, normal.z);
	set_vec(&(new->point), p.x, p.y, p.z);
	return (new);
}

/// Computes if a plane intersects a certain ray and returns the distance. If it doesnt returns -1
/// \param plane
/// \param ray
/// \return distance to plane intersect or -1 if parallel
double	plane_intersect(t_plane *plane, t_line ray)
{
	double	angle;

	unit_vector2(ray.direction, &ray.direction);
	angle = dot_prod(plane->normal, ray.direction);
	if (angle == 0)
		return (-1);
	vec_subtract(plane->point, ray.point, &ray.point);
	return (dot_prod(plane->normal, ray.point) / angle);
}