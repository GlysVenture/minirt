/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:38:16 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:38:16 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 2/7/22.
//

#include "key_handler.h"
#include "mlx.h"
#include "minirt.h"
#include "object.h"

int	key_handler(int keycode, t_vars *v)
{
	if (keycode == key_esc)
	{
		mlx_destroy_image(v->mu->mlx, v->mu->img.img);
		mlx_destroy_window(v->mu->mlx, v->mu->win);
		ft_lstclear(&v->obj, (void (*)(void *)) destroy_obj);
		ft_lstclear(&v->lights, free);
		exit(0);
	}
	return (0);
}

int	ftquit(t_vars *v)
{
	mlx_destroy_image(v->mu->mlx, v->mu->img.img);
	mlx_destroy_window(v->mu->mlx, v->mu->win);
	ft_lstclear(&v->obj, (void (*)(void *)) destroy_obj);
	ft_lstclear(&v->lights, free);
	exit(0);
}
