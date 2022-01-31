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
void	ft_sheer(char *dir, t_matrix m,double l);
void	ft_rotate(char dir, t_matrix m, double l);
void	ft_aggr(char dir, t_matrix m, double l);
int	free_tab(char **tab);

#endif
