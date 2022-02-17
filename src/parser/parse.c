/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:47:12 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/16 18:01:57 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "mrt.h"
#include "minirt.h"
#include "geotrace.h"
#include "debug/debug.h"

int		hexcolor(char *line);
void	tr_free(t_object *obj, char **tf[2]);

int	parse_camera(char *line, t_camera *cam)
{
	char	**args[2];

	args[0] = ft_split(line, ' ');
	args[1] = ft_split(args[0][1], ',');
	set_vec(cam->origin, ft_atod(args[1][0]), ft_atod(
			args[1][1]), ft_atod(args[1][2]));
	free_tab(args[1]);
	args[1] = ft_split(args[0][2], ',');
	set_vec(cam->direction, ft_atod(args[1][0]), ft_atod(args[1][1]), ft_atod(
			args[1][2]));
	if (inrange(cam->direction, -1.0, 1.0) == 0)
	{
		error("invalid values",args);
		return (0);
	}
	cam->angle = radians(ft_atod(args[0][3]));
	if (isless(ft_atod(args[0][3]), 0.0) || isgreater(ft_atod(args[0][3]), 180.0))
	{
		error("invalid values",args);
		return (0);
	}
	free_tab(args[0]);
	free_tab(args[1]);
	return (1);
}

int	parse_sphere(char *line, t_vars *v)
{
	t_object	*obj;
	t_list		*new;

	obj = check_sphere(line);
	if (!obj)
		return (0);
	new = ft_lstnew(obj);
	if (!new)
	{
		destroy_obj(obj);
		return (0);
	}
	ft_lstadd_front(&v->obj, new);
	return (1);
}

int	parse_plane(char *line, t_vars *v)
{
	t_object	*obj;
	t_list		*new;

	obj = check_plane(line);
	if (!obj)
		return (0);
	new = ft_lstnew(obj);
	if (!new)
	{
		destroy_obj(obj);
		return (0);
	}
	ft_lstadd_front(&v->obj, new);
	return (1);
}

int	parse_cylinder(char *line, t_vars *v)
{
	char	**args;
	char	**nargs;

	args = ft_split(line, ' ');
	line = ft_strjoin("cylinder matrix ", args[1]);
	line = ft_strjoin(line, " az ");
	line = ft_strjoin(line, args[4]);
	line = ft_strjoin(line, " ax ");
	line = ft_strjoin(line, args[3]);
	line = ft_strjoin(line, " ay ");
	line = ft_strjoin(line, args[3]);
	nargs = ft_split(args[2], ',');
	line = ft_strjoin(line, " rx ");
	line = ft_strjoin(line, nargs[0]);
	line = ft_strjoin(line, " ry ");
	line = ft_strjoin(line, nargs[1]);
	line = ft_strjoin(line, " rz ");
	line = ft_strjoin(line, nargs[2]);
	line = ft_strjoin(line, " colors ");
	line = ft_strjoin(line, args[5]);
	line = ft_strjoin(line, " 255,255,255 0.2,0.7,0.35");
	free_tab(nargs);
	free_tab(args);
	return (parse_object(line, v));
}

int	parse_light(char *line, t_vars *v)
{
	void	*mem;
	t_list	*new;

	mem = check_light(line);
	if (!mem)
		return (0);
	new = ft_lstnew(mem);
	if (!new)
	{
		free(mem);
		return (0);
	}
	ft_lstadd_front(&v->lights, new);
	return (1);
}
