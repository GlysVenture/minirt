//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "debug.h"
#include "geotrace.h"
#include "libft.h"
#include "object.h"
#include "light/light.h"
#include <stdio.h>

void	print_ray(t_line ray)
{
	printf("vector:\npoint\n%f\n%f\n%f\ndir\n%f\n%f\n%f\n", ray.point.x, ray.point.y, ray.point.z, ray.direction.x, ray.direction.y, ray.direction.z);
}

void	print_point(t_vec3d point)
{
	printf("point\n%f\n%f\n%f\n", point.x, point.y, point.z);
}

void	print_objlst(t_list *obj)
{
	while (obj)
	{
		print_obj((t_object *)obj->content);
		obj = obj->next;
	}
}

void	print_obj(t_object *obj)
{
	if (obj->type == 's')
	{
		printf("sphere:\ncenter ");
		print_point(((t_sphere *)obj->structure)->center);
		printf("radius: %f\n", ((t_sphere *)obj->structure)->radius);
	}
	else if (obj->type == 'p')
	{
		printf("plane:\nnormal ");
		print_point(((t_plane *)obj->structure)->normal);
		printf("any ");
		print_point(((t_plane *)obj->structure)->point);
	}
	else
	{
		printf("unknown: %c\n", obj->type);
	}
	printf("color: %x\n", obj->color);
}

void	print_lights(t_list *lights)
{
	while (lights)
	{
		printf("light:\norigin ");
		print_point(((t_light *)lights->content)->pos);
		printf("color: %x\n", ((t_light *)lights->content)->color);
		lights = lights->next;
	}
}
