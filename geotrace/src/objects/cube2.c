/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:36 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:36 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 2/2/22.
//

#include <math.h>
#include <float.h>

#include "geotrace.h"
#include "cube.h"

int	get_x_int(double res[], t_line *ray)
{
	if (fabs(ray->direction[0]) <= FLT_EPSILON)
	{
		if (islessequal(ray->point[0], 1) && isgreaterequal(ray->point[0], 0))
			return (-1);
		return (0);
	}
	res[0] = (1 - ray->point[0]) / ray->direction[0];
	res[1] = -ray->point[0] / ray->direction[0];
	if (isless(res[1], res[0]))
		swap(res, res + 1);
	return (1);
}

int	get_y_int(double res[], t_line *ray)
{
	if (fabs(ray->direction[1]) <= FLT_EPSILON)
	{
		if (islessequal(ray->point[1], 1) && isgreaterequal(ray->point[1], 0))
			return (-1);
		return (0);
	}
	res[0] = (1 - ray->point[1]) / ray->direction[1];
	res[1] = -ray->point[1] / ray->direction[1];
	if (isless(res[1], res[0]))
		swap(res, res + 1);
	return (1);
}

int	get_z_int(double res[], t_line *ray)
{
	if (fabs(ray->direction[2]) <= FLT_EPSILON)
	{
		if (islessequal(ray->point[2], 1) && isgreaterequal(ray->point[2], 0))
			return (-1);
		return (0);
	}
	res[0] = (1 - ray->point[2]) / ray->direction[2];
	res[1] = -ray->point[2] / ray->direction[2];
	if (isless(res[1], res[0]))
		swap(res, res + 1);
	return (1);
}

void	add_bounds(double res[], double temp[])
{
	if (isless(res[0], temp[0]))
		res[0] = temp[0];
	if (isgreater(res[1], temp[1]))
		res[1] = temp[1];
}
