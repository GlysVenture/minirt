#ifndef MRT_H
# define MRT_H

#include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "../object.h"
#include "geotrace.h"
#include "light/light.h"
#include "minirt.h"

t_sphere *check_sphere(char *arg,  int *color);
int	get_arg(char *filename, t_vars *v);
t_plane	*check_plane(char *arg,  int *color);
double ft_atod(const char *arr);
t_light	*check_light(char *line);
double get_coordinates(char **line);
typedef struct s_cylinder
{
	t_vec3d center;
	t_vec3d orient;
	double diameter;
	double height;
}	t_cylinder;
void	free_tab(char **tab);
t_cylinder *check_cylinder(char *line, int *color);
t_cylinder *init_cylinder(double cx,double cy, double cz,t_vec3d or,double height, double diameter);
#endif
