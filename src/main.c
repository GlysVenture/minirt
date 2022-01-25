#include <stdio.h>
#include <math.h>
#include <float.h>

#include "mlx.h"

#include "key_handler.h"
#include "geotrace.h"
#include "camera.h"
#include "libft.h"
#include "object.h"
#include "light.h"
#include "colors/colors.h"

#include "debug/debug.h"

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

static void	vec_get_normal(char type, void *s, t_vec3d temp,t_vec3d *normal)
{
	if (type == 's')
		vec_subtract(((t_sphere *)s)->center, temp, normal);
	if (type == 'p')
		*normal = ((t_plane *)s)->normal;
}

static int	send_ray(t_line *ray, t_list *obj)
{
	double	dist;
	double	t;
	int		color;
	t_light	light = {{2, -2, 3}, 0x00FFFFFF};
	t_vec3d temp;
	t_list	*start_obj;
	t_vec3d	normal;
	char	obj_type;

	start_obj = obj;
	dist = -1;
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, *ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, *ray);
		if (isgreater(t, FLT_EPSILON) && (dist < 0 || isless(t, dist)))
		{
			dist = t;
			unit_vector2(ray->direction, &temp);
			scalar_mult2(temp, dist, &temp);
			vec_sum(temp, ray->point, &temp);
			vec_get_normal(obj_type, ((t_object *)obj->content)->structure, temp, &normal); //todo find better sol for normal
			color = ((t_object *)obj->content)->color;
		}
		obj = obj->next;
	}
	if (isless(dist, 0))
		return (0x00000000);
	t = shadow_ray(temp, light, start_obj, normal);
	if (isless(t, 0))
		color = 0;
	else
		color = shift_color2(color,(t / M_PI_2 - 1));
	return (color);
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
	t_plane	plane = {{-0, 0, -1}, {6, 0, -0.1}};
	t_sphere sphere = {{4, 0, 0}, 0.2};
	t_sphere sphere2 = {{6, 0, 0.5}, 0.4};
	t_sphere sphere3 = {{4, 0.2, 1}, 0.13};

	t_list *objects;

	ft_lstadd_front(&objects, ft_lstnew(init_obj('s', &sphere, 0x00FFF000)));
	ft_lstadd_front(&objects, ft_lstnew(init_obj('s', &sphere2, 0x00FF0000)));
	ft_lstadd_front(&objects, ft_lstnew(init_obj('s', &sphere3, 0x0000FF1A)));
	ft_lstadd_front(&objects, ft_lstnew(init_obj('p', &plane, 0x0000FFF0)));

	launch_window(&objects);

	ft_lstclear(&objects, (void (*)(void *))destroy_obj);
	return (0);
}
