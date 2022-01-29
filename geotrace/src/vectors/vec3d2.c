//
// Created by tkondrac on 21.01.22.
//

#include <math.h>
#include <stdlib.h>

#include "geotrace.h"

/// Sets vector to (x,y,z)
/// \param v vector
/// \param x coord
/// \param y coord
/// \param z coord
double	*set_vec(t_vec3d v, const double x, const double y, const double z)
{
	v[0] = x;
	v[1] = y;
	v[2] = z;
	return (v);
}

/// Sets vector to another vector
/// \param v vector to be set
/// \param u source vector
double	*set_vec2(t_vec3d v, const t_vec3d u)
{
	v[0] = u[0];
	v[1] = u[1];
	v[2] = u[2];
	return (v);
}

/// Computes sum of 2 vectors
/// \param v vector
/// \param u vector
/// \param new sum vector
double	*vec_sum(const t_vec3d v, const t_vec3d u, t_vec3d new)
{
	new[0] = v[0] + u[0];
	new[1] = v[1] + u[1];
	new[2] = v[2] + u[2];
	return (new);
}

/// Computes subtraction of 2 vectors
/// \param v vector
/// \param u vector
/// \param new substract vector
double	*vec_subtract(const t_vec3d v, const t_vec3d u, t_vec3d new)
{
	new[0] = v[0] - u[0];
	new[1] = v[1] - u[1];
	new[2] = v[2] - u[2];
	return (new);
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
