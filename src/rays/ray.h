//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef RAY_H
# define RAY_H

#include "libft.h"
#include "geotrace.h"
#include "minirt.h"
#include "object.h"

typedef struct s_intersect
{
	t_object	obj;
	double		dist;
	t_line		in_ray;
	t_vec3d		hit;
	t_vec3d		normal;
	double		amb_l[3];
	double		diff_l[3];
	double		spec_l[3];
}	t_intersect;

int		send_ray(t_line *ray, t_vars *v);
int		shadow_ray(t_line *ray, t_list *obj);

double	diffuse_shade(t_intersect *intersect, t_line *ray);
double	specular_shade(t_intersect *intersect, t_line *ray);

#endif //RAY_H
