//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "parse.h"
#include "mrt.h"
#include "minirt.h"

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
	int i;
	int b;

	b = -1;
	i = 0;
	(void)v;
	while (*line != ' ')
		line++;
	line++;
	while (++b < 3)
		coor[b] = get_coordinates(&line,&i);
	b = -1;
	line--;
	while (++b < 3)
		orienta[b] = get_coordinates(&line, &i);
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
	ft_lstadd_front(&v->obj, new);
	return (1);
}
