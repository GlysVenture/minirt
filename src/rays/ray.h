//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef RAY_H
# define RAY_H

#include "libft.h"
#include "geotrace.h"
#include "minirt.h"

int		send_ray(t_line *ray, t_vars *v);
double	shadow_ray(t_vec3d start, t_vars *v, t_vec3d n);

#endif //RAY_H
