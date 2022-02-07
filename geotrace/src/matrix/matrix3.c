/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:28 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:28 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 02.02.22.
//

#include "geotrace.h"
#include <stdio.h>

/// Multiplies matrix by scalar
/// \param a matrix
/// \param scalar
/// \param b result matrix
/// \return scalar * a
double	**matrix_scalar_mult(const t_matrix a, double scalar, t_matrix b)
{
	scalar_mult(a[0], scalar, b[0]);
	scalar_mult(a[1], scalar, b[1]);
	scalar_mult(a[2], scalar, b[2]);
	return ((double **) b);
}

/// Prints matrix to STDOUT
/// \param a matrix
void	print_matrix(const t_matrix a)
{
	printf("matrix\n");
	printf("| %.3f : %.3f : %.3f |\n", a[0][0], a[0][1], a[0][2]);
	printf("| %.3f : %.3f : %.3f |\n", a[1][0], a[1][1], a[1][2]);
	printf("| %.3f : %.3f : %.3f |\n", a[2][0], a[2][1], a[2][2]);
	printf("determinant : %.3f\n", matrix_determinant(a));
}

//todo
void	set_id_matrix(t_matrix matrix)
{
	matrix[0][1] = 0;
	matrix[0][2] = 0;
	matrix[1][0] = 0;
	matrix[1][2] = 0;
	matrix[2][0] = 0;
	matrix[2][1] = 0;
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
}
