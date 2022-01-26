//
// Created by Tadeusz Kondracki on 1/25/22.
//

#ifndef LIGHT_H
# define LIGHT_H

#include "geotrace.h"
#include "libft.h"

typedef struct s_light
{
	t_vec3d	pos;
	int		color;
}	t_light;

typedef struct s_amb_light
{
	double	ratio;
	int		color;
}	t_amb_light;

t_light	*init_light(t_vec3d pos, int color);

#endif //LIGHT_H
