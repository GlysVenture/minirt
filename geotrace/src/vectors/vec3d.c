//
// Created by tkondrac on 21.01.22.
//

#include <stdlib.h>
#include <math.h>

#include "geotrace.h"

/// Multiplication of a vector by a scalar. For an implementation without memory allocation see scalar_mult2()
/// \param v vector
/// \param a scalar
/// \return memory allocated [t_vec3d*] scalar * vector
t_vec3d	*scalar_mult(const t_vec3d v, const double a)
{
	t_vec3d	*new;

	new = malloc(sizeof(t_vec3d));
	if (!new)
		return (NULL);
	new->x = a * v.x;
	new->y = a * v.y;
	new->z = a * v.z;
	return (new);
}

/// Computes scalar product.
/// \param v vector
/// \param u vector
/// \return scalar product
double	dot_prod(t_vec3d v, t_vec3d u)
{
	return (v.x * u.x + v.y * u.y + v.z * u.z);
}

/// Computes vector product. For an implementation without memory allocation see vec_prod2()
/// \param v vector
/// \param u vector
/// \return memory allocated [t_vec3d*] vector product
t_vec3d	*vec_prod(const t_vec3d v, const t_vec3d u)
{
	t_vec3d	*new;

	new = malloc(sizeof(t_vec3d));
	if (!new)
		return (NULL);
	new->x = v.y * u.z - v.z * u.x;
	new->y = v.z * u.x - v.x * u.z;
	new->z = v.x * u.y - v.y * u.x;
	return (new);
}

/// Computes the norm aka lenght of a given vector
/// \param v vector
/// \return vector norm
double	vec_norm(const t_vec3d v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

/// Computes unit vector aka vector with length 1. For an implementation without
///// memory allocation see unit_vector2()
/// \param v vector
/// \return memory allocated [t_vec3d*] unit vector
t_vec3d	*unit_vector(const t_vec3d v)
{
	return (scalar_mult(v, 1 / vec_norm(v)));
}
