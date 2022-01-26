#ifndef MRT_H
# define MRT_H

#include "libft.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "object.h"
#include "geotrace.h"
typedef struct s_alight
{
	float	ratio;
	int 	colors[3];
} t_alight;
char	*get_next_line(int fd);
void *check_sphere(char *arg);
char	*get_arg(char	*filename);
void	*check_plane(char *arg);
float ft_atof(char *arr);
void	launch_window(t_list **objects);
#endif
