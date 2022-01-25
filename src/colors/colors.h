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
int		shift_color2(int color, double shift);
//void	set_colors(int *colors, int iter, int seed);

#endif //COLORS_H
