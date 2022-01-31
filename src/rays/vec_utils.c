//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include <math.h>
#include <stdio.h>

#include "vec_utils.h"
#include "debug/debug.h"
#include "ray.h"
#include "geotrace.h"

void	vec_get_normal(t_intersect *intersect)
{
	if (intersect->obj.type == 's')
		vec_subtract(intersect->hit, ((t_sphere *)intersect->obj.structure)->center, intersect->normal);
	if (intersect->obj.type == 'p')
		set_vec2(intersect->normal, ((t_plane *)intersect->obj.structure)->normal);

	if (isless(get_angle(intersect->normal, intersect->in_ray.direction), M_PI_2))
		scalar_mult(intersect->normal, -1, intersect->normal);
}

double	cos_angle(const t_vec3d u, const t_vec3d v)
{
	return (dot_prod(u, v) / (vec_norm(v) * vec_norm(u)));
}
