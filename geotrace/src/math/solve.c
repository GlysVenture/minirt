/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:24 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:24 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 30.01.22.
//

#include <math.h>
#include <float.h>

#include <stdio.h>

/// Converts from degrees to radians
/// \param deg angle in degrees [0,360[
/// \return angle in radians
double	radians(double deg)
{
	return (deg * M_PI * 2 / 360);
}

/// swaps 2 double pointers
/// \param a
/// \param b
void	swap(double *a, double *b)
{
	double	t;

	t = *a;
	*a = *b;
	*b = t;
}

/// Solves normalized quadratic ax^2 + bx + c equation (where a = 1)
/// \param quad [2] with c and b
/// \param res [2] empty
void	solve_quad(const double quad[], double res[])
{
	double	delta;

	delta = pow(quad[1], 2) - 4 * quad[0] * 1;
	if (isless(delta, FLT_EPSILON))
		res[0] = -1;
	else if (fabs(delta) <= FLT_EPSILON)
		res[0] = -quad[1] / 2;
	else
	{
		res[0] = (sqrt(delta) - quad[1]) / 2;
		res[1] = - (sqrt(delta) + quad[1]) / 2;
		if (isgreaterequal(res[1], FLT_EPSILON)
			&& isgreaterequal(res[0], FLT_EPSILON)
			&& isless(res[1], res[0]))
			swap(res, res + 1);
	}
}
