#include <stdio.h>
#include "geotrace.h"
#include "../camera.h"
#include "libft.h"
#include "../object.h"
#include "mrt.h"
t_vec3d	get_center(char *line)
{
	char	**ret;
	int	i;
	t_vec3d	r;
	i = 0;
	ret = ft_split(line, ',');
	while (ret[i])
		i++;
	if (i != 3)
	{
		printf("Error cord\n");
		exit (1);
	}
	r.x = ft_atod(ret[0]);
	r.y = ft_atod(ret[1]);
	r.z = ft_atod(ret[2]);
	return (r);
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
void	*check_plane(char *arg, long unsigned int *color)
{
	char **ret;
	t_plane	pl;
	void	*ptr;
	ret = ft_split(arg, ' ');
	pl.normal = get_center(ret[1]);
	pl.point = get_center(ret[2]);
	*color = hexcolor(ret[3]);
	free (ret);
	ptr = &pl;
	return (ptr);
}

void	*check_sphere(char *arg, long unsigned int *color)
{
	char **ret;
	void	*ptr;
	t_sphere	sphere;
	ret = ft_split(arg,' ');
	sphere.center = get_center(ret[1]);
	sphere.radius = ft_atod(ret[2]);
	*color = hexcolor(ret[3]);
	free(ret);
	ptr = &sphere;
	return (ptr);
}	
