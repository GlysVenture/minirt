#ifndef MRT_H
# define MRT_H

#include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "geotrace.h"
#include "minirt.h"


t_object	*check_sphere(char *arg);
t_object	*check_plane(char *arg);
t_light		*check_light(char *line);

int	get_arg(char *filename, t_vars *v);

double get_coordinates(char **line);

void	ft_sheer(char *dir, t_matrix m,double l);
void	ft_rotate(char dir, t_matrix m, double l);
void	ft_aggr(char dir, t_matrix m, double l);

int	free_tab(char **tab);
double ft_atod(const char *arr);

#endif
