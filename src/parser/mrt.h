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
	int 	colors[3];
} t_alight;
void *check_sphere(char *arg, long unsigned int *color);
char	*get_arg(char	*filename);
void	*check_plane(char *arg, long unsigned int *color);
double ft_atod(char *arr);
#endif
