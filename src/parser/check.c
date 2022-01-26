#include <stdio.h>
#include "geotrace.h"
#include "../camera.h"
#include "libft.h"
#include "../object.h"
#include "mrt.h"
void	get_center(char *line, double radius, t_sphere *sphere)
{
	char	**ret;
	int	i;
	i = 0;
	ret = ft_split(line, ',');
	while (ret[i])
		i++;
	if (i != 3)
	{
		printf("Error cord\n");
		exit (1);
	}

	sphere = init_sphere(radius, ft_atod(ret[0]), ft_atod(ret[1]), ft_atod(ret[2]));
	return;
}

long unsigned int  hexcolor(char *line)
{
	int r, g, b;
	char **ret;

	ret = ft_split(line,',');
	r = ft_atoi(ret[0]);
	g = ft_atoi(ret[1]);
	b = ft_atoi(ret[2]);
    	return (r<<16) | (g<<8) | b;
}
t_plane	*check_plane(char *arg, long unsigned int *color)
{
	char **ret;
	char **mem;
	t_plane	*pl;
	t_vec3d n;
	t_vec3d p;
	
	ret = ft_split(arg, ' ');
	mem = ft_split(ret[1], ',');
	n.x =  ft_atod(mem[0]);
	n.y = ft_atod(mem[1]);
	n.z = ft_atod(mem[2]);
	free (mem);
	mem = NULL;
	mem = ft_split(ret[2], ',');
	p.x = ft_atod(mem[0]);
	p.y = ft_atod(mem[1]);
	p.z = ft_atod(mem[2]);
	free (mem);
	pl = init_plane(n,p);
	*color = hexcolor(ret[3]);
	return (pl);
}

t_sphere	*check_sphere(char *arg, long unsigned int *color)
{
	char **tes;
	char **ret;
	t_sphere	*sphere;


	tes = ft_split(arg,' ');
	ret = ft_split(tes[1], ',');
	sphere = init_sphere(ft_atod(tes[2]), ft_atod(ret[0]), ft_atod(ret[1]), ft_atod(ret[2]));
	*color = hexcolor(tes[3]);
	return (sphere);
}	
