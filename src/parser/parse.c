//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "parse.h"
#include "mrt.h"
#include "minirt.h"
#include "geotrace.h"

#include "debug/debug.h"
int hexcolor(char *line);

int	parse_sphere(char *line, t_vars *v)
{
	t_object *obj;
	t_list	*new;

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
	t_object *obj;
	t_list	*new;

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

/*int	parse_cylinder(char *line, t_vars *v)
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
}*/

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

void	parse_colors(t_object *obj, char **args)
{
	int		i;
	char	**nargs;

	i = 0;
	while (ft_strncmp(args[i],"colors",7))
		i++;
	obj->colors[0] = hexcolor(args[i + 1]);
	obj->colors[1] = hexcolor(args[i + 2]);
	nargs = ft_split(args[i + 3], ',');
	obj->k_ratio[0] = ft_atod(nargs[0]);
	obj->k_ratio[1] = ft_atod(nargs[1]);
	obj->k_ratio[2] = ft_atod(nargs[2]);

}

void	parse_int_matrix(t_matrix matrix,char *name, char *args)
{
	if (name[0] == 's')
		ft_sheer(name + 1,matrix, ft_atod(args));
	else if (name[0] == 'r')
		ft_rotate(name[1],matrix, ft_atod(args));
	else if (name[0] == 'a')
		ft_aggr(name[1],matrix, ft_atod(args));
}

int parse_matrix(t_object *obj, char **args)
{
	int	i;
	char **nargs;

	i = 0;
	while (args[i] != NULL && ft_strncmp(args[i], "matrix",7))
		i++;
	nargs = ft_split(args[i + 1],',');
	if (!nargs)
		return (0);
	obj->tr_vec[0] = ft_atod(nargs[0]);
	obj->tr_vec[1] = ft_atod(nargs[1]);
	obj->tr_vec[2] = ft_atod(nargs[2]);
	i += 2;
	set_id_matrix(obj->transformation);
	while (args[i])
	{
		if (!ft_strncmp(args[i], "colors",8))
			break;
		else
			parse_int_matrix(obj->transformation,args[i],args[i + 1]);
		i += 2;
	}
	if (args[i] == NULL)
		return (free_tab(nargs));
	inverse_matrix(obj->transformation, obj->inv);
	matrix_transpose(obj->inv,obj->inv_transp);
	free_tab(nargs);
	return (1);
}
	
int	parse_object(char *line, t_vars *v)
{
	t_object	*obj;
	char		type;
	char		**args;
	t_list		*new;

	
	args = ft_split(line, ' ');
	if (!args)
		return (free_tab(args));
	type = get_type(args[0]);
	if (!type)
		return (free_tab(args));
	obj = init_object(type);
	new = ft_lstnew(obj);
	if (!new)
	{
		destroy_obj(obj);
		return (free_tab(args));
	}
	if (parse_matrix(obj, args + 1) == 0)
	{
		destroy_obj(obj);
		return (free_tab(args));
	}
	parse_colors(obj, args + 1);
	ft_lstadd_front(&v->obj, new);
	free_tab(args);
	return (1);
}
