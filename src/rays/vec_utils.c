//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "vec_utils.h"
#include "geotrace.h"

double	cos_angle(const t_vec3d u, const t_vec3d v)
{
	return (dot_prod(u, v) / (vec_norm(v) * vec_norm(u)));
}
