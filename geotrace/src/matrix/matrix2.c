//
// Created by tkondrac on 28.01.22.
//

#include <stdio.h>

#include "geotrace.h"

/// Computes the transpose of matrix
/// \param a matrix
/// \param b pointer to result matrix
double	**matrix_transpose(const t_matrix a, t_matrix b)
{
	t_vec3d v[3];

	v[0][0] = a[0][0];
	v[0][1] = a[1][0];
	v[0][2] = a[2][0];
	v[1][0] = a[0][1];
	v[1][1] = a[1][1];
	v[1][2] = a[2][1];
	v[2][0] = a[0][2];
	v[2][1] = a[1][2];
	v[2][2] = a[2][2];
	set_matrix(b, v[0], v[1], v[2]);
	return ((double **) b);
}

double	get_cofactor(const t_matrix a, int r, int c)
{
	double val;

	val = a[(r + 1) % 3][(c + 1) % 3]
			* a[(r + 2) % 3][(c + 2) % 3]
		- a[(r + 2) % 3][(c + 1) % 3]
			* a[(r + 1) % 3][(c + 2) % 3];
	return (val);
}

double	matrix_determinant(const t_matrix a)
{
	double	d;

	d = a[0][0] * get_cofactor(a, 0, 0);
	d += a[0][1] * get_cofactor(a, 0, 1);
	d += a[0][2] * get_cofactor(a, 0, 2);
	return (d);
}

double	**cofactor_matrix(const t_matrix a, t_matrix c)
{
	t_vec3d v[3];

	v[0][0] = get_cofactor(a, 0, 0);
	v[0][1] = get_cofactor(a, 0, 1);
	v[0][2] = get_cofactor(a, 0, 2);
	v[1][0] = get_cofactor(a, 1, 0);
	v[1][1] = get_cofactor(a, 1, 1);
	v[1][2] = get_cofactor(a, 1, 2);
	v[2][0] = get_cofactor(a, 2, 0);
	v[2][1] = get_cofactor(a, 2, 1);
	v[2][2] = get_cofactor(a, 2, 2);
	set_matrix(c, v[0], v[1], v[2]);
	return ((double **) c);
}

double	**matrix_scalar_mult(const t_matrix a, double scalar, t_matrix b)
{
	scalar_mult(a[0], scalar, b[0]);
	scalar_mult(a[1], scalar, b[1]);
	scalar_mult(a[2], scalar, b[2]);
	return ((double **) b);
}

double	**inverse_matrix(t_matrix a, t_matrix b)
{
	cofactor_matrix(a, b);
	matrix_transpose(b, b);
	matrix_scalar_mult(b, 1 / matrix_determinant(a), b);
	return ((double **) b);
}

void	print_matrix(const t_matrix a)
{
	printf("matrix\n");
	printf("| %.3f : %.3f : %.3f |\n", a[0][0], a[0][1], a[0][2]);
	printf("| %.3f : %.3f : %.3f |\n", a[1][0], a[1][1], a[1][2]);
	printf("| %.3f : %.3f : %.3f |\n", a[2][0], a[2][1], a[2][2]);
	printf("determinant : %.3f\n", matrix_determinant(a));
}
