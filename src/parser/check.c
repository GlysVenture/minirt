#include <stdio.h>
#include "geotrace.h"
#include "../camera.h"
#include "libft.h"
#include "../object.h"
#include "mrt.h"
#include "light/light.h"

int  hexcolor(char *line)
{
	int r, g, b;
	char **ret;

	ret = ft_split(line,',');
	r = ft_atoi(ret[0]);
	g = ft_atoi(ret[1]);
	b = ft_atoi(ret[2]);
	free_tab(ret);
    	return (r<<16) | (g<<8) | b;
}
t_plane	*check_plane(char *arg, int *color)
{
	char **ret;
	char **mem;
	t_plane	*pl;
	t_vec3d n;
	t_vec3d p;
	
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
	pl = init_plane(n,p);
	*color = hexcolor(ret[3]);
	free_tab(ret);
	return (pl);
}

t_sphere	*check_sphere(char *arg, int *color)
{
	int i;
	int j;
	double vals[4];
	t_sphere	*sphere;

	i = 0;
	j = 1;
	while (arg[i] != ' ')
		i++;
	i++;
	vals[0] = ft_atod(arg + i);
	while (arg[i])
	{
		if (arg[i] == ',')
		{
			vals[j] = ft_atod(arg + i + 1);
			j++;
		}
		else if (arg[i] == ' ')
		{
			i++;
			vals[j] = ft_atod(arg + (i));
			j++;
			break;
		}
		i++;
	}
	while (arg[i])
	{
		if (arg[i] == ' ')
			*color = hexcolor(arg + i + 1);
		i++;
	}
	sphere = init_sphere(vals[3], vals[0], vals[1], vals[2]);
	return (sphere);
}

double get_coordinates(char **line, int *i)
{
	double ret;

	*i = 1;
	if (**line == ',')
		*line += 1;
	ret = ft_atod(*line);
	while (**line != ',')
		*line += 1;
	//printf("%s\n", *line);
	return (ret);
}

t_light	*check_light(char *line)
{
	int i;
	int j;
	t_light *light;
	t_vec3d temp;
	double vals[4];

	i = 0;
	j = 1;
	while (line[i] != ' ')
		i++;
	vals[0] = ft_atod(line + i + 1);
	i++;
	while (line[i] != ' ')
	{
		if (line[i] == ',')
		{
			vals[j] = ft_atod(line + i + 1);
			j++;
		}
		i++;
	}
	i++;
	vals[3] = ft_atod(line + i + 1);
	set_vec(temp, vals[0], vals[1],vals[2]);
	while (line[i] != ' ')
		i++;
	i++;
	light = init_light(temp, hexcolor(line + i), vals[3]);
	return (light);
}

