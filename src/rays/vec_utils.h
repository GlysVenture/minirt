//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef VEC_UTILS_H
# define VEC_UTILS_H

#include "geotrace.h"
#include "ray.h"

void	vec_get_normal(t_intersect *intersect);

double	cos_angle(const t_vec3d u, const t_vec3d v);

#endif //VEC_UTILS_H
