/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:42:01 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:42:01 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/25/22.
//

#ifndef LIGHT_H
# define LIGHT_H

# include "geotrace.h"
# include "libft.h"

typedef struct s_light
{
	t_vec3d	pos;
	int		color;
	double	ratio;
}	t_light;

typedef struct s_amb_light
{
	double	ratio;
	int		color;
}	t_amb_light;

t_light	*init_light(t_vec3d pos, int color, double ratio);

#endif //LIGHT_H
