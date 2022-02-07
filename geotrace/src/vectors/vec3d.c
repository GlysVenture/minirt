/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:41 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:41 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 21.01.22.
//

#include <math.h>

#include "geotrace.h"

/// Multiplication of a vector by a scalar.
/// \param v vector
/// \param a scalar
///	\param w uninitialized scaled vector
/// \return a * v
double	*scalar_mult(const t_vec3d v, const double a, t_vec3d w)
{
	w[0] = a * v[0];
	w[1] = a * v[1];
	w[2] = a * v[2];
	return (w);
}

/// Computes scalar product.
/// \param v vector
/// \param u vector
/// \return scalar product
double	dot_prod(const t_vec3d v, const t_vec3d u)
{
	return (v[0] * u[0] + v[1] * u[1] + v[2] * u[2]);
}

/// Computes vector product.
/// \param v vector
/// \param u vector
///	\param w uninitialized product vector
/// \return u ^ v
double	*vec_prod(const t_vec3d v, const t_vec3d u, t_vec3d w)
{
	t_vec3d	t;

	t[0] = v[1] * u[2] - v[2] * u[1];
	t[1] = v[2] * u[0] - v[0] * u[2];
	w[2] = v[0] * u[1] - v[1] * u[0];
	w[0] = t[0];
	w[1] = t[1];
	return (w);
}

/// Computes the norm aka lenght of a given vector
/// \param v vector
/// \return vector norm
double	vec_norm(const t_vec3d v)
{
	return (sqrt(pow(v[0], 2) + pow(v[1], 2) + pow(v[2], 2)));
}

/// Computes unit vector aka vector with length 1.
/// \param v vector
///	\param unit uninitialized unit vector
/// \return unit vector
double	*unit_vector(t_vec3d v, t_vec3d unit)
{
	return (scalar_mult(v, 1 / vec_norm(v), unit));
}
