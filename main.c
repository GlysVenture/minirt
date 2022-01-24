#include <stdio.h>

#include "mlx.h"

#include "geotrace.h"
#include "camera.h"
#include "libft.h"
#include "object.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

static void	ft_mlx_putpixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	send_ray(t_line *ray, t_list *obj)
{
	double	dist;
	double	t;
	int		color;

	dist = -1;
	while(obj)
	{
		t = -2;
		if (((t_object *)obj->content)->type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, *ray);
		if (((t_object *)obj->content)->type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, *ray);
		if (t >= 0 && (dist < 0 || t < dist))
		{
			dist = t;
			color = ((t_object *)obj->content)->color;
		}
		obj = obj->next;
	}
	if (dist < 0)
		return (0x00000000);
	return (color);
}

static void	fill_image(t_data *img, int x, int y, t_list **obj)
{
	int			i;
	int			j;
	t_line		ray;
	t_camera	cam = {{-2, 0.3, 0}, {1, 0, 0}, 90};
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
	if (keycode == 53)
	{
		exit(0); //todo free all mem
	}
	return (0);
}

static void	launch_window(t_list **objects)
{
	void	*mlx;
	void	*win;
	t_data	img;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 700, 700, "raytracer");
	img.img = mlx_new_image(mlx, 700, 700);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);

	fill_image(&img, 700, 700, objects);

	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_key_hook(win, key_handler, NULL);
	mlx_loop(mlx);
}

int main() {
	t_plane	plane = {{-0, 0, 1}, {6, 0, -0.1}};
	t_sphere sphere = {{4, 0, 0}, 0.2};
	t_sphere sphere2 = {{6, 0, 0.5}, 0.4};
	t_sphere sphere3 = {{4, 0.1, -0.04}, 0.17};

	t_list *objects;

	ft_lstadd_front(&objects, ft_lstnew(init_obj('s', &sphere, 0x00FFF000)));
	ft_lstadd_front(&objects, ft_lstnew(init_obj('s', &sphere2, 0x00FF0000)));
	ft_lstadd_front(&objects, ft_lstnew(init_obj('s', &sphere3, 0x0000FF1A)));
	ft_lstadd_front(&objects, ft_lstnew(init_obj('p', &plane, 0x0000FFF0)));

	launch_window(&objects);

	ft_lstclear(&objects, (void (*)(void *))destroy_obj);
	return (0);
}
