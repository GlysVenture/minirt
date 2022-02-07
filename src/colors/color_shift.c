/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:40:48 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:40:48 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "colors.h"
#include <math.h>

void	unpack_color(double color[], int color2, double ratio)
{
	color[0] = ratio * (double)get_red(color2) / 255;
	color[1] = ratio * (double)get_green(color2) / 255;
	color[2] = ratio * (double)get_blue(color2) / 255;
}

void	color_scalar(double color[], double scalar)
{
	color[0] *= scalar;
	color[1] *= scalar;
	color[2] *= scalar;
}

void	clamp(double color[], double min, double max)
{
	if (isless(color[0], min))
		color[0] = min;
	else if (isgreater(color[0], max))
		color[0] = max;
	if (isless(color[1], min))
		color[1] = min;
	else if (isgreater(color[1], max))
		color[1] = max;
	if (isless(color[2], min))
		color[2] = min;
	else if (isgreater(color[2], max))
		color[2] = max;
}

void	set_color(double color[], double r, double g, double b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

void	set_color2(double color[], const double color2[])
{
	color[0] = color2[0];
	color[1] = color2[1];
	color[2] = color2[2];
}
