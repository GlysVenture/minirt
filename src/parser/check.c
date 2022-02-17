/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:16:54 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/16 18:01:07 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "geotrace.h"
#include "../camera.h"
#include "libft.h"
#include "../object.h"
#include "mrt.h"
#include "light/light.h"
#include "debug/debug.h"
#include <float.h>

void	set_default(t_object **obj, char name);

int	hexcolor(char *line)
{
	int		rgb[3];
	char	**ret;

	ret = ft_split(line, ',');
	rgb[0] = ft_atoi(ret[0]);
	rgb[1] = ft_atoi(ret[1]);
	rgb[2] = ft_atoi(ret[2]);
	free_tab(ret);
	if ((rgb[0] > 255 || rgb[1] > 255 || rgb[2] > 255) || (
			rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0))
	{
		printf("Error invalid colors\n");
		return (-1);
	}
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	adjust_plane(t_vec3d n[3], t_object *plane)
{
	set_vec2(n[2], n[0]);
	n[2][2] = 0;
	set_vec(n[1], 0, 1, 0);
	ft_rotate('z', plane->transformation, (get_angle(n[2], n[1]) * -1));
	set_vec(n[1], 0, 0, 1);
	ft_rotate('y', plane->transformation, (get_angle(n[0], n[1]) * -1));
}

t_object	*check_plane(char *arg)
{
	char		**ret[2];
	t_object	*plane;
	t_vec3d		n[3];

	ret[0] = ft_split(arg, ' ');
	ret[1] = ft_split(ret[0][2], ',');
	if (!ret[1] || !nbrargs(ret[0], 5) || !nbrargs(ret[1], 3))
		return (error("", ret));
	set_vec(n[0], ft_atod(ret[1][0]), ft_atod(ret[1][1]), ft_atod(ret[1][2]));
	free_tab (ret[1]);
	ret[1] = ft_split(ret[0][1], ',');
	set_default(&plane, 'p');
	if (!(set_vec(plane->tr_vec, ft_atod(ret[1][0]),
			ft_atod(ret[1][1]), ft_atod(ret[1][2]))))
		return (error("", ret));
	if (inrange(plane->tr_vec, -1.1, 1.1) == 0 || inrange(n[0], -1.1, 1.1) == 0)
		return (error("incorrect plane values", ret));
	if (fabs(n[0][0]) > FLT_EPSILON || fabs(n[0][1]) > FLT_EPSILON)
		adjust_plane(n, plane);
	plane->colors[0] = hexcolor(ret[0][3]);
	if (plane->colors[0] == -1)
		return (error("", ret));
	tr_free(plane, ret);
	return (plane);
}

t_object	*check_sphere(char *arg)
{
	char		**args[2];
	t_object	*sphere;

	args[0] = ft_split(arg, ' ');
	args[1] = ft_split(args[0][1], ',');
	if (isless(ft_atod(args[0][2]), 0.1) || args[0] == NULL || args[1]
			== NULL)
		return (error("Incorrect args value", args));
	if (!nbrargs(args[1], 3))
		return (error("Incorrect nbr of arguments", args));
	set_default(&sphere, 's');
	set_vec(sphere->tr_vec, ft_atod(args[1][0]),
		ft_atod(args[1][1]), ft_atod(args[1][2]));
	matrix_scalar_mult(sphere->transformation,
		ft_atod(args[0][2]), sphere->transformation);
	sphere->colors[0] = hexcolor(args[0][3]);
	free_tab(args[0]);
	free_tab(args[1]);
	if (sphere->colors[0] == -1)
		return (NULL);
	inverse_matrix(sphere->transformation, sphere->inv);
	matrix_transpose(sphere->inv, sphere->inv_transp);
	return (sphere);
}

t_light	*check_light(char *line)
{
	char	**args[2];
	t_light	*light;
	t_vec3d	temp;

	args[0] = ft_split(line, ' ');
	if (!nbrargs(args[0], 4))
		return (error("wrong nbr of args", args));
	args[1] = ft_split(args[0][1], ',');
	if (!args[1])
		return (error("Fatal malloc error", args));
	set_vec(temp, ft_atod(args[1][0]),
		ft_atod(args[1][1]), ft_atod(args[1][2]));
	if (isgreater(ft_atod(args[0][2]), 1.0) || isless(
		ft_atod(args[0][2]), 0.1))
		return (error("Incorrect ratio", args));
	if (hexcolor(args[0][3]) == -1)
		return (error("", args));
	free_tab(args[1]);
	light = init_light(temp, hexcolor(args[0][3]), ft_atod(args[0][2]));
	free_tab(args[0]);
	return (light);
}
