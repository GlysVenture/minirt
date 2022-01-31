//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "parse.h"
#include "mrt.h"
#include "minirt.h"

#include "debug/debug.h"
int hexcolor(char *line);
void	set_id_matrix(t_matrix matrix);

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
	double o[3];
	int color;
	int b;
	double dimensions[2];
	t_matrix	m;
	b = -1;
	t_vec3d y;

	y[0] = 0;
	y[1] = 0;
	y[2] = 1;
	while (*line != ' ')
		line++;
	line++;
	while (++b < 3)
		coor[b] = get_coordinates(&line);
	b = -1;
	line--;
	while (++b < 3)
		o[b] = get_coordinates(&line);
	b = -1;
	while (++b < 2)
		dimensions[b] = get_coordinates(&line);
	color = hexcolor(line);
	set_id_matrix(m);
	ft_rotate('y',m,(get_angle(y,o) * -1));
	(void)v;
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

int parse_colors(t_object *obj, char **args)
{
	int	i;

	i = 0;
	while (ft_strncmp(args[i],"colors",8))
		i++;
	obj->colors[0] = ft_atoi(args[0]);
	obj->colors[1] = ft_atoi(args[1]);
	return (1);
}
void	set_id_matrix(t_matrix matrix)
{
	ft_memset(matrix,0,sizeof(t_matrix));
	matrix[0][0] = 1;
	matrix[1][1] = 1;
	matrix[2][2] = 1;
}

int	parse_int_matrix(t_matrix matrix,char *name, char *args)
{
	int	i;

	i = 0;
	if (name[0] == 's')
		ft_sheer(name + 1,matrix, ft_atod(args));
	else if (name[0] == 'r')
		ft_rotate(name[1],matrix, ft_atod(args));
	else if (name[0] == 'a')
		ft_aggr(name[1],matrix, ft_atod(args));
	return (1);
}

int parse_matrix(t_object *obj, char **args)
{
	int	i;
	char **nargs;

	i = 0;
	while (ft_strncmp(args[i], "matrix",7))
		i++;
	nargs = ft_split(args[i + 1],',');
	if (!nargs)
		return (0);
	obj->tr_vec[0] = ft_atod(nargs[i + 1]);
	obj->tr_vec[1] = ft_atod(nargs[i + 2]);
	obj->tr_vec[2] = ft_atod(nargs[i + 3]);
	i += 2;
	set_id_matrix(obj->transformation);
	while (args[i])
	{
		if (!ft_strncmp(args[i], "colors",8))
			break;
		else
			if (parse_int_matrix(obj->transformation,args[i],args[i + 1]) == 0)
				return (free_tab(nargs));
		i += 2;
	}
	free_tab(nargs);
	return (1);
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
	if (parse_matrix(obj, args + 1) == 0)
		return (free_tab(args));
	if (parse_colors(obj, args + 1) == 0)
		return (free_tab(args));
	(void)v;
	return (1);
}
