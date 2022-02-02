//
// Created by tkondrac on 02.02.22.
//

#include "geotrace.h"

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
