//
// Created by Tadeusz Kondracki on 1/24/22.
//

#include <math.h>
#include <stdlib.h>

#include "camera.h"
#include "geotrace.h"

t_adv_camera	*set_advanced_camera(t_camera *cam, int x, int y, t_line *ray)
{
	double			tmp;
	t_adv_camera	*new;
	t_vec3d			v;

	new = malloc(sizeof(t_adv_camera));
	if(!new)
		return (NULL);
	set_vec2(new->horizontal, cam->direction);
	new->horizontal[2] = 0;
	tmp = new->horizontal[0];
	new->horizontal[0] = -new->horizontal[1];
	new->horizontal[1] = tmp;
	tmp = vec_norm(cam->direction) * tan(cam->angle / 2);
	unit_vector(new->horizontal, new->horizontal);
	scalar_mult(new->horizontal, tmp / (x - 1), new->horizontal);
	vec_prod(cam->direction, new->horizontal, new->vertical);
	unit_vector(new->vertical, new->vertical);
	scalar_mult(new->vertical, -tmp / (y - 1), new->vertical);
	new->cam = *cam;
	set_vec2(ray->point, cam->origin);
	scalar_mult(new->horizontal, (double)(x - 1) / -2, v);
	vec_sum(cam->direction, v, ray->direction);
	scalar_mult(new->vertical, (double)(y - 1) / -2, v);
	vec_sum(ray->direction, v, ray->direction);
	return (new);
}
