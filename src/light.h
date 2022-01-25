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

double	shadow_ray(t_vec3d start, t_light light, t_list *obj, t_vec3d n);

#endif //LIGHT_H
