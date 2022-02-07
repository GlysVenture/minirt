/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_shift2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:40:48 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:40:48 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 2/7/22.
//

#include "colors.h"

void	color_sum(double color[], const double color2[])
{
	color[0] += color2[0];
	color[1] += color2[1];
	color[2] += color2[2];
}

void	color_sum2(double color[], const double color2[], double scalar)
{
	color[0] += scalar * color2[0];
	color[1] += scalar * color2[1];
	color[2] += scalar * color2[2];
}

void	color_sum3(double color[], const int color2)
{
	color[0] += (double)get_red(color2) / 255;
	color[1] += (double)get_green(color2) / 255;
	color[2] += (double)get_blue(color2) / 255;
}

void	color_mult(double color[], int color2)
{
	color[0] *= (double)get_red(color2) / 255;
	color[1] *= (double)get_green(color2) / 255;
	color[2] *= (double)get_blue(color2) / 255;
}

void	color_mult2(double color[], int color2, double scalar)
{
	color[0] *= scalar * (double)get_red(color2) / 255;
	color[1] *= scalar * (double)get_green(color2) / 255;
	color[2] *= scalar * (double)get_blue(color2) / 255;
}
