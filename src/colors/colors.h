/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
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

#ifndef COLORS_H
# define COLORS_H

//TRGB color manipulation
int		create_color(int t, int r, int g, int b);
int		get_transparency(int color);
int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		shift_color(int c, int c2, double shift);
int		shift_color2(int c, int c2, double shift);
int		shift_black(int c, double shift);

//double [3] precise color manips
void	unpack_color(double color[], int color2, double intensity);
void	color_mult(double color[], int color2);
void	color_mult2(double color[], int color2, double scalar);
void	color_scalar(double color[], double scalar);
void	color_sum(double color[], const double color2[]);
void	color_sum2(double color[], const double color2[], double scalar);
void	clamp(double color[], double min, double max);

//void	set_colors(int *colors, int iter, int seed);

#endif //COLORS_H
