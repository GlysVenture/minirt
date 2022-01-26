//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef RAY_H
# define RAY_H

#include "libft.h"
#include "geotrace.h"
#include "minirt.h"
#include "object.h"

int		send_ray(t_line *ray, t_vars *v);
int		shadow_ray(t_vec3d start, t_light light, t_list *obj);

int		diffuse_shade(t_object *intersect, t_vec3d hit, t_line *ray, t_vars *v);

#endif //RAY_H
