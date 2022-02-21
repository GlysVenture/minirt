/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:38:16 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/21 17:23:08 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include <float.h>

#include "mlx.h"

#include "key_handler.h"
#include "geotrace.h"
#include "camera.h"
#include "libft.h"
#include "object.h"
#include "parser/mrt.h"
#include "light/light.h"
#include "colors/colors.h"
#include "minirt.h"
#include "rays/ray.h"
#include "mlx_utils.h"

#include "debug/debug.h"

#define WIN_X 1000

static void	fill_xline(t_data *img, t_line ray, t_vars *v, int j)
{
	int	i;

	i = 0;
	while (i < WIN_X)
	{
		vec_sum(ray.direction, v->cam.horizontal, ray.direction);
		ft_mlx_putpixel(img, i, j, send_ray(&ray, v));
		i++;
	}
}

static void	fill_image(t_data *img, t_vars *v)
{
	int				j;
	t_line			ray;

	set_advanced_camera(&v->cam, WIN_X, WIN_X, &ray);
	j = 0;
	while (j < WIN_X)
	{
		fill_xline(img, ray, v, j);
		vec_sum(ray.direction, v->cam.vertical, ray.direction);
		j++;
	}
}

void	launch_window(t_vars *v)
{
	t_mlx_utils	mu;

	mu.mlx = mlx_init();
	mu.win = mlx_new_window(mu.mlx, WIN_X, WIN_X, "raytracer");
	mu.img.img = mlx_new_image(mu.mlx, WIN_X, WIN_X);
	mu.img.addr = mlx_get_data_addr(mu.img.img, &mu.img.bits_per_pixel,
			&mu.img.line_length, &mu.img.endian);
	v->mu = &mu;
	fill_image(&mu.img, v);
	mlx_put_image_to_window(mu.mlx, mu.win, mu.img.img, 0, 0);
	mlx_key_hook(mu.win, key_handler, v);
	mlx_hook(mu.win, 17, 0, ftquit, v);
	mlx_loop(mu.mlx);
}

static void	init_vars(t_vars *v)
{
	v->lights = NULL;
	v->obj = NULL;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error: arguments");
		return (1);
	}
	init_vars(&vars);
	if (get_arg(argv[1], &vars) == 0)
		return (0);
	if (!vars.lights || !vars.obj || !vars.ambient.ratio || !vars.cam.cam.angle)
	{
		printf("Error critical objects missing\n");
		ft_lstclear(&vars.obj, (void (*)(void *)) destroy_obj);
		ft_lstclear(&vars.lights, free);
		return (0);
	}
	launch_window(&vars);
	return (0);
}
