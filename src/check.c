#include <stdio.h>
#include "geotrace.h"
#include "camera.h"
#include "libft.h"
#include "object.h"
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
	r.x = ft_atof(ret[0]);
	r.y = ft_atof(ret[1]);
	r.z = ft_atof(ret[2]);
	return (r);
}
void	*check_plane(char *arg, int color)
{
	char **ret;
	t_plane	pl;
	void	*ptr;
	ret = ft_split(arg, ' ');
	pl.normal = get_center(ret[1]);
	pl.point = get_center(ret[2]);
	free (ret);
	ptr = &pl;
	return (ptr);
}
void	*check_sphere(char *arg, int color)
{
	char **ret;
	void	*ptr;
	t_sphere	sphere;
	ret = ft_split(arg,' ');
	sphere.center = get_center(ret[1]);
	sphere.radius = ft_atof(ret[2]);
	free(ret);
	ptr = &sphere;
	return (ptr);
}	
