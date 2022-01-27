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

#include "debug/debug.h"

#define WIN_X 1000

static void	ft_mlx_putpixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	fill_image(t_data *img, int x, int y, t_vars *v)
{
	int			i;
	int			j;
	t_line		ray;
	t_camera	cam = {{0, 0.2, 1}, {1, 0, 0}, M_PI_2};
	t_adv_camera	*cam_adv;
	t_vec3d		temp;

	cam_adv = set_advanced_camera(&cam, x, y, &ray);
	i = 0;
	j = 0;
	while(j < y)
	{
		temp = ray.direction;
		while (i < x)
		{
			vec_sum(ray.direction, cam_adv->horizontal, &ray.direction);
			ft_mlx_putpixel(img, i, j, send_ray(&ray, v));
			i++;
		}
		vec_sum(temp, cam_adv->vertical, &ray.direction);
		i = 0;
		j++;
	}
	free(cam_adv);
}

static int	key_handler(int keycode, t_vars *v)
{
	printf("debug: key pressed: %d\n", keycode);
	(void)v;
	if (keycode == key_esc)
	{
//		ft_lstclear(&v->obj, (void (*)(void *))destroy_obj);
//		ft_lstclear(&v->lights, (void (*)(void *))destroy_obj);
		exit(0);
	}
	return (0);
}

void	launch_window(t_vars *v)
{
	t_mlx_utils	mu;

	mu.mlx = mlx_init();
	mu.win = mlx_new_window(mu.mlx, WIN_X, WIN_X, "raytracer");
	mu.img.img = mlx_new_image(mu.mlx, WIN_X, WIN_X);
	mu.img.addr = mlx_get_data_addr(mu.img.img, &mu.img.bits_per_pixel, &mu.img.line_length,
		&mu.img.endian);

	fill_image(&mu.img, WIN_X, WIN_X, v);

	mlx_put_image_to_window(mu.mlx, mu.win, mu.img.img, 0, 0);
	mlx_key_hook(mu.win, key_handler, v);
	mlx_loop(mu.mlx);
}

static void	init_vars(t_vars *v)
{
	v->lights = NULL;
	v->obj = NULL;
}

//static void magic(t_list __attribute__((unused)) *lights)
//{
//}

int main(int argc, char *argv[]) 
{
	t_vars	vars;

	if (argc != 2)
	{
		printf("Error: arguments");
		return (1);
	}
	init_vars(&vars);
	get_arg(argv[1], &vars);
//	print_lights(vars.lights);
//	magic(vars.lights);
	launch_window(&vars);
	//ft_lstclear(&vars.obj, (void (*)(void *))destroy_obj);
	//ft_lstclear(&vars.lights, (void (*)(void *))destroy_obj);
	return (0); 
}
