/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 16:27:40 by tkondrac          #+#    #+#             */
/*   Updated: 2021/11/14 16:27:40 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 10/31/21.
//

#include "colors.h"
#include <math.h>
#include <float.h>

int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_red(int color)
{
	return ((color >> 16) & 255);
}

int	get_green(int color)
{
	return ((color >> 8) & 255);
}

int	get_blue(int color)
{
	return (color & 255);
}

int	shift_color(int c, int c2, double shift)
{
	if (shift > 1)
		shift = shift - (int)(shift);
	return (create_color(0,
			get_red(c) + (int)((get_red(c2) - get_red(c)) * shift),
		get_green(c) + (int)((get_green(c2) - get_green(c)) * shift),
			get_blue(c) + (int)((get_blue(c2) - get_blue(c)) * shift)));
}
