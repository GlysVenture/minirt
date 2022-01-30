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
	if (r > 255 || g > 255 || b > 255)
	{
		printf("Error invalid colors\n");
		return (-1);
	}
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
	char **ret;
	char **coor;

	t_sphere	*sphere;
	ret = ft_split(arg,' ');
	coor = ft_split(ret[1],',');
	*color = hexcolor(ret[3]);
	sphere = init_sphere(ft_atod(ret[2]),ft_atod(coor[0]),ft_atod(coor[1]), ft_atod(coor[2]));
	free_tab(ret);
	free_tab(coor);
	return (sphere);
}
/*t_cylinder	*check_cylinder(char *arg, int *color)
{
	char **ret;
	char **coor;
	char **orienta;
	t_vec3d or;
	t_cylinder *cylinder;

	ret = ft_split(arg, ' ');
	coor = ft_split(ret[1],',');
	*color = hexcolor(ret[5]);
	orienta = ft_split(ret[2], ',');
	or[0] = ft_atod(orienta[0]);
	or[1] = ft_atod(orienta[1]);
	or[2] = ft_atod(orienta[2]);
	cylinder = init_cylinder(ft_atod(coor[0]),ft_atod(coor[1]),ft_atod(coor[2]),or,ft_atod(ret[3]),ft_atod(ret[4]));
	free_tab(ret);
	free_tab(coor);
	free_tab(orienta);
	return (cylinder);
} */

t_light	*check_light(char *line)
{
	t_light *light;
	t_vec3d temp;
	char **vals;
	char **coor;

	vals = ft_split(line, ' ');
	coor = ft_split(vals[1], ',');
	set_vec(temp,ft_atod(coor[0]),ft_atod(coor[1]),ft_atod(coor[2]));
	free_tab(coor);
	light = init_light(temp, hexcolor(vals[3]),ft_atod(vals[2]));
	free_tab(vals);
	return (light);
}

