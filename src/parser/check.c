#include <stdio.h>
#include "geotrace.h"
#include "../camera.h"
#include "libft.h"
#include "../object.h"
#include "mrt.h"
#include "light/light.h"
#include "debug/debug.h"
#include <float.h>

int  hexcolor(char *line)
{
	int r, g, b;
	char **ret;

	ret = ft_split(line,',');
	r = ft_atoi(ret[0]); //todo check valid
	g = ft_atoi(ret[1]);
	b = ft_atoi(ret[2]);
	if ((r > 255 || g > 255 || b > 255) || (r < 0 || g < 0 || b < 0))
	{
		printf("Error invalid colors\n");
		return (-1);
	}
	free_tab(ret);
    	return (r<<16) | (g<<8) | b;
}
t_object	*check_plane(char *arg)
{
	char **ret;
	char **mem;
	t_object	*plane;
	t_vec3d n;
	t_vec3d p;
	t_vec3d temp;

	ret = ft_split(arg, ' ');
	mem = ft_split(ret[1], ',');
	n[0] =  ft_atod(mem[0]);
	n[1] = ft_atod(mem[1]);
	n[2] = ft_atod(mem[2]);
	free_tab (mem);
	mem = NULL;
	mem = ft_split(ret[2], ',');
	p[0] = ft_atod(mem[0]);
	p[1] = ft_atod(mem[1]);
	p[2] = ft_atod(mem[2]);
	free_tab (mem);

	plane = init_object('p');
	set_vec(plane->tr_vec, p[0], p[1], p[2]);
	set_id_matrix(plane->transformation);
	if (fabs(n[0]) > FLT_EPSILON || fabs(n[1]) > FLT_EPSILON)
	{
		set_vec2(temp, n);
		temp[2] = 0;
		set_vec(p, 0, 1, 0);
		ft_rotate('z', plane->transformation, (get_angle(temp,p) * -1));
	}
	set_vec(p, 0, 0, 1);
	ft_rotate('y',plane->transformation,(get_angle(n,p) * -1));
	plane->colors[0] = hexcolor(ret[3]);
	plane->colors[1] = 0xFFFFFF;
	plane->k_ratio[0] = 0.1;
	plane->k_ratio[1] = 0.7;
	plane->k_ratio[2] = 0.2;

	inverse_matrix(plane->transformation, plane->inv);
	matrix_transpose(plane->inv, plane->inv_transp);
	free_tab(ret);
	return (plane);
}

t_object	*check_sphere(char *arg)
{
	char **args;
	char **nargs;
	t_object	*sphere;


	args = ft_split(arg, ' ');
	nargs = ft_split(args[1], ',');
	sphere = init_object('s');
	set_vec(sphere->tr_vec, ft_atod(nargs[0]), ft_atod(nargs[1]), ft_atod(nargs[2]));
	set_id_matrix(sphere->transformation);
	matrix_scalar_mult(sphere->transformation, ft_atod(args[2]), sphere->transformation);
	sphere->colors[0] = hexcolor(args[3]);
	sphere->colors[1] = 0xFFFFFF;
	sphere->k_ratio[0] = 0.1;
	sphere->k_ratio[1] = 0.7;
	sphere->k_ratio[2] = 0.2;
	inverse_matrix(sphere->transformation, sphere->inv);
	matrix_transpose(sphere->inv, sphere->inv_transp);
	free_tab(args);
	free_tab(nargs);
	return (sphere);
}

t_light	*check_light(char *line)
{
	char **args;
	char **nargs;
	t_light *light;
	t_vec3d temp;

	args = ft_split(line, ' ');
	nargs = ft_split(args[1], ',');
	set_vec(temp, ft_atod(nargs[0]), ft_atod(nargs[1]), ft_atod(nargs[2]));
	free_tab(nargs);
	light = init_light(temp, hexcolor(args[3]), ft_atod(args[2]));
	return (light);
}

