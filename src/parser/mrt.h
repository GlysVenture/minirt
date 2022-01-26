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
typedef struct s_alight
{
	float	ratio;
	long unsigned int color;
} t_alight;
t_sphere *check_sphere(char *arg, long unsigned int *color);
char	*get_arg(char	*filename);
t_plane	*check_plane(char *arg, long unsigned int *color);
double ft_atod(char *arr);
#endif
