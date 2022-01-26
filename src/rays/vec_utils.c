//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "vec_utils.h"

void	vec_get_normal(char type, void *s, t_vec3d temp,t_vec3d *normal)
{
	if (type == 's')
		vec_subtract(((t_sphere *)s)->center, temp, normal);
	if (type == 'p')
		*normal = ((t_plane *)s)->normal;
}
