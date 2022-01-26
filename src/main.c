#include <stdio.h>
#include <math.h>
#include <float.h>

#include "mlx.h"

#include "key_handler.h"
#include "geotrace.h"
#include "camera.h"
#include "libft.h"
#include "object.h"
#include "mrt.h"
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

static void	fill_image(t_data *img, int x, int y, t_list **obj)
{
	int			i;
	int			j;
	t_line		ray;
	t_camera	cam = {{0, 0.5, 2}, {1, -0.1, -0.3}, M_2_PI};
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
			ft_mlx_putpixel(img, i, j, send_ray(&ray, *obj));
			i++;
		}
		vec_sum(temp, cam_adv->vertical, &ray.direction);
		i = 0;
		j++;
	}
	free(cam_adv);
}

static int	key_handler(int keycode, void *t)
{
	(void) t;
	printf("debug: key pressed: %d\n", keycode);
	if (keycode == key_esc)
	{
		exit(0); //todo free all mem
	}
	return (0);
}

	void	launch_window(t_list **objects)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIN_X, WIN_X, "raytracer");
	img.img = mlx_new_image(mlx, WIN_X, WIN_X);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);

	fill_image(&img, WIN_X, WIN_X, objects);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_key_hook(win, key_handler, NULL);
	mlx_loop(mlx);
}

int main(int argc, char *argv[]) 
{
	get_arg(argv[1]);
	argc = 0;
	return (0); 
}
