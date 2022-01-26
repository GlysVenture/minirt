//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include <math.h>
#include <float.h>

#include "ray.h"
#include "geotrace.h"
#include "libft.h"
#include "../light/light.h"
#include "../object.h"
#include "../colors/colors.h"
#include "vec_utils.h"

int	send_ray(t_line *ray, t_list *obj)
{
	double	dist;
	double	t;
	int		color;
	t_light	light = {{2, -2, 3}, 0x00FFFFFF};
	t_vec3d temp;
	t_list	*start_obj;
	t_vec3d	normal;
	char	obj_type;
	//t_list	found;

	start_obj = obj;
	dist = -1;
	while(obj)
	{
		t = -2;
		obj_type = ((t_object *)obj->content)->type;
		if (obj_type == 's')
			t = sphere_intersect(((t_object *)obj->content)->structure, *ray);
		if (obj_type == 'p')
			t = plane_intersect(((t_object *)obj->content)->structure, *ray);
		if (isgreater(t, FLT_EPSILON) && (dist < 0 || isless(t, dist)))
		{
			dist = t;
			unit_vector2(ray->direction, &temp);
			scalar_mult2(temp, dist, &temp);
			vec_sum(temp, ray->point, &temp);
			vec_get_normal(obj_type, ((t_object *)obj->content)->structure, temp, &normal); //todo find better sol for normal
			color = ((t_object *)obj->content)->color;
		}
		obj = obj->next;
	}
	if (isless(dist, 0))
		return (0x00000000);
	t = shadow_ray(temp, light, start_obj, normal);
	if (isless(t, 0))
		color = 0;
	else
		color = shift_color2(color,(t / M_PI_2 - 1));
	return (color);
}
