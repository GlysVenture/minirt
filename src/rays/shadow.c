//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include "object.h"
#include <math.h>
#include <float.h>

#include "ray.h"
#include "minirt.h"
#include "vec_utils.h"


int	shadow_ray(t_vec3d start, t_light light, t_list *obj)
{
	double	dist;
	double	t;
	t_line	ray;
	char	obj_type;

	ray.point = start;
	vec_subtract(light.pos, start, &ray.direction);
	dist = vec_norm(ray.direction);
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, ray);
		if (isgreater(t, FLT_EPSILON) && (isless(dist, 0) || isless(t, dist)))
			return (-1);
		obj = obj->next;
	}
	return (1);
}

/*int	diffuse_shade(t_object *intersect, t_vec3d hit, t_line *ray, t_vars *v)
{
	double	angle;
	t_vec3d	normal;

	vec_get_normal(intersect->type, intersect->structure, hit, &normal); // todo once
	angle = get_angle();
}*/
