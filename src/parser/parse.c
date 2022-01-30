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

/*int	parse_cylinder(char *line, t_vars *v)
{
	void	*mem;
	t_list	*new;
	int	color;

	mem = check_cylinder(line, &color);
	if (!mem)
		return (0);
	new = ft_lstnew(init_obj(line[0],mem,color));
	if (!new)
	{
		free(mem);
		return (0);
	}
	ft_lstadd_front(&v->lights,new);
	return (1);
} */
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
