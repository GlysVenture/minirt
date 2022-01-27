//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include <stdio.h>

#include "light.h"
#include "libft.h"

t_light	*init_light(t_vec3d pos, int color, double ratio)
{
	t_light *new;

	new = malloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->color = color;
	new->pos = pos;
	new->ratio = ratio;
	return (new);
}
