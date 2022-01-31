//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "parse.h"
#include "mrt.h"
#include "minirt.h"

#include "debug/debug.h"
int hexcolor(char *line);
int	parse_sphere(char *line, t_vars *v)
{
	int		color;
	void	*mem;
	t_list	*new;

	mem = check_sphere(line, &color);
	if (!mem)
		return (0);
	new = ft_lstnew(init_obj(line[0], mem, color));
	if (!new)
	{
		free(mem);
		return (0);
	}
	ft_lstadd_front(&v->obj, new);
	return (1);
}

int	parse_plane(char *line, t_vars *v)
{
	int		color;
	void	*mem;
	t_list	*new;

	mem = check_plane(line, &color);
	if (!mem)
		return (0);
	new = ft_lstnew(init_obj(line[0], mem, color));
	if (!new)
	{
		free(mem);
		return (0);
	}
	ft_lstadd_front(&v->obj, new);
	return (1);
}

int	parse_cylinder(char *line, t_vars *v)
{
	double coor[3];
	double orienta[3];
	int color;
	int b;
	double dimensions[2];

	b = -1;
	(void)v;
	while (*line != ' ')
		line++;
	line++;
	while (++b < 3)
		coor[b] = get_coordinates(&line);
	b = -1;
	line--;
	while (++b < 3)
		orienta[b] = get_coordinates(&line);
	b = -1;
	while (++b < 2)
		dimensions[b] = get_coordinates(&line);
	color = hexcolor(line);
	(void) color;
	(void) dimensions;
	(void) coor;
	(void) orienta;
	return (1);
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

/// todo
/// we need, parse object which gets line, splits, stores char type, finds colors args, finds matrix args. and calls appropriate funcs with those. optional are params. Must be compatible with basic input and advanced

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

int	parse_object(char *line, t_vars *v)
{
	t_object	*obj;
	char		type;
	char		**args;

	args = ft_split(line, ' ');
	if (!args)
		return (free_tab(args));
	type = get_type(args[0]);
	if (!type)
		return (free_tab(args));
	obj = init_object(type);
	parse_matrix(obj, args + 1);
	parse_colors(obj, args + 1);
}
