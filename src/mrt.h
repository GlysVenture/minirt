#ifndef MRT_H
# define MRT_H

#include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
typedef struct s_alight
{
	float	ratio;
	int 	colors[3];
} t_alight;
char	*get_next_line(int fd);
int	check_sphere(char *arg);
char	*get_arg(char	*filename);
float ft_atof(char *arr);
#endif
