/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:42:00 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:42:00 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include <stdio.h>

#include "light.h"
#include "libft.h"

t_light	*init_light(t_vec3d pos, int color, double ratio)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->color = color;
	set_vec2(new->pos, pos);
	new->ratio = ratio;
	return (new);
}
