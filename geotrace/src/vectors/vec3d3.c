//
// Created by tkondrac on 22.01.22.
//

#include <math.h>
#include <stdlib.h>

#include "geotrace.h"

/// Computes sum of 2 vectors
/// \param v vector
/// \param u vector
/// \param new pointer to result vector
void	vec_sum(const t_vec3d v, const t_vec3d u, t_vec3d *new)
{
	new->x = v.x + u.x;
	new->y = v.y + u.y;
	new->z = v.z + u.z;
}

/// Computes subtraction of 2 vectors
/// \param v vector
/// \param u vector
/// \param new pointer to result vector
void	vec_subtract(const t_vec3d v, const t_vec3d u, t_vec3d *new)
{
	new->x = v.x - u.x;
	new->y = v.y - u.y;
	new->z = v.z - u.z;
}

/// Computes angle between 2 vectors
/// \param v vector
/// \param u vector
/// \return angle
double	get_angle(const t_vec3d v, const t_vec3d u)
{
	double	a;

	a = dot_prod(v, u);
	a /= (vec_norm(v) * vec_norm(u));
	return (acos(a));
}
