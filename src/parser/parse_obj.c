/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:26:10 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/20 17:25:10 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "mrt.h"
#include "minirt.h"
#include "geotrace.h"
#include "debug/debug.h"
#include "parse_obj.h"

static char	get_type(char *str)
{
	if (!ft_strncmp("sphere", str, 7))
		return ('s');
	if (!ft_strncmp("cube", str, 5))
		return ('#');
	if (!ft_strncmp("plane", str, 6))
		return ('p');
	if (!ft_strncmp("cylinder", str, 9))
		return ('c');
	return (0);
}

void	parse_colors(t_object *obj, char **args)
{
	int		i;
	char	**nargs;

	i = 0;
	while (ft_strncmp(args[i], "colors", 7))
		i++;
	obj->colors[0] = hexcolor(args[i + 1]);
	obj->colors[1] = hexcolor(args[i + 2]);
	nargs = ft_split(args[i + 3], ',');
	if (!nbrargs(nargs, 3))
		obj->colors[0] = -1;
	obj->k_ratio[0] = ft_atod(nargs[0]);
	obj->k_ratio[1] = ft_atod(nargs[1]);
	obj->k_ratio[2] = ft_atod(nargs[2]);
}

void	parse_int_matrix(t_matrix matrix, char *name, char *args)
{
	if (name[0] == 's')
		ft_sheer(name + 1, matrix, ft_atod(args));
	else if (name[0] == 'r')
		ft_rotate(name[1], matrix, ft_atod(args));
	else if (name[0] == 'a')
		ft_aggr(name[1], matrix, ft_atod(args));
}

int	parse_matrix(t_object *obj, char **args)
{
	int		i;
	char	**nargs;

	i = 0;
	while (args[i] != NULL && ft_strncmp(args[i], "matrix", 7))
		i++;
	nargs = ft_split(args[i + 1], ',');
	if (!nargs || args[i] == NULL)
		return (0);
	set_vec(obj->tr_vec, ft_atod(nargs[0]), ft_atod(
			nargs[1]), ft_atod(nargs[2]));
	i += 2;
	set_id_matrix(obj->transformation);
	while (args[i] && ft_strncmp(args[i], "colors", 8))
	{
		parse_int_matrix(obj->transformation, args[i], args[i + 1]);
		i += 2;
	}
	if (args[i] == NULL)
		return (free_tab(nargs));
	tr_free(obj, NULL);
	free_tab(nargs);
	return (1);
}

int	parse_object(char *line, t_vars *v)
{
	t_object	*obj;
	char		**args;
	t_list		*new;

	args = ft_split(line, ' ');
	if (!args)
		return (free_tab(args));
	if (!get_type(args[0]))
		return (free_tab(args));
	obj = init_object(get_type(args[0]));
	new = ft_lstnew(obj);
	parse_colors(obj, args + 1);
	if (!new || parse_matrix(obj, args + 1) == 0 || obj->colors[0]
		== -1 || obj->colors[1] == -1)
	{
		write(2, "Error\n", 6);
		destroy_obj(obj);
		return (free_tab(args));
	}
	ft_lstadd_front(&v->obj, new);
	free_tab(args);
	return (1);
}
