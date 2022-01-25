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
	new->horizontal = cam->direction;
	tmp = new->horizontal.x;
	new->horizontal.x = -new->horizontal.y;
	new->horizontal.y = tmp;
	tmp = vec_norm(cam->direction) * cos(cam->angle);
	unit_vector2(new->horizontal, &new->horizontal);
	scalar_mult2(new->horizontal, (-tmp) / (x - 1), &new->horizontal);
	vec_prod2(cam->direction, new->horizontal, &new->vertical);
	unit_vector2(new->vertical, &new->vertical);
	scalar_mult2(new->vertical, tmp / (y - 1), &new->vertical);
	new->cam = *cam;
	scalar_mult2(new->horizontal, (double)(x - 1) / -2, &v);
	vec_sum(cam->direction, v, &ray->direction);
	scalar_mult2(new->vertical, (double)(y - 1) / -2, &v);
	vec_sum(ray->direction, v, &ray->direction);
	return (new);
}
