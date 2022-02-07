/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:28 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:28 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 28.01.22.
//

#include "geotrace.h"

/// Sets the values of an existing matrix
/// \param a matrix
/// \param x 1st row
/// \param y 2nd row
/// \param z 3rd row
double	**set_matrix(t_matrix a, const t_vec3d x,
		const t_vec3d y, const t_vec3d z)
{
	a[0][0] = x[0];
	a[0][1] = x[1];
	a[0][2] = x[2];
	a[1][0] = y[0];
	a[1][1] = y[1];
	a[1][2] = y[2];
	a[2][0] = z[0];
	a[2][1] = z[1];
	a[2][2] = z[2];
	return ((double **) a);
}

/// Multiplies given vector by a matrix
/// \param a matrix
/// \param v vector
/// \param u pointer to result vector
double	*matrix_vect_prod(const t_matrix a, const t_vec3d v, t_vec3d u)
{
	t_vec3d	t;

	t[0] = dot_prod(a[0], v);
	t[1] = dot_prod(a[1], v);
	u[2] = dot_prod(a[2], v);
	u[0] = t[0];
	u[1] = t[1];
	return (u);
}

/// Computes Matrix multiplication
/// \param a matrix
/// \param b matrix
/// \param c result matrix
double	**matrix_prod(t_matrix a, t_matrix b, t_matrix c)
{
	t_matrix	ct;
	t_matrix	t;

	matrix_transpose(b, ct);
	matrix_vect_prod(a, ct[0], t[0]);
	matrix_vect_prod(a, ct[1], t[1]);
	matrix_vect_prod(a, ct[2], t[2]);
	matrix_transpose(t, c);
	return ((double **) c);
}
