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
	printf("vector:\npoint\n%f\n%f\n%f\ndir\n%f\n%f\n%f\n", ray.point[0], ray.point[1], ray.point[2], ray.direction[0], ray.direction[1], ray.direction[2]);
}

void	print_point(t_vec3d point)
{
	printf("point\n%f\n%f\n%f\n", point[0], point[1], point[2]);
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
		printf("--- sphere ---\n");
	else if (obj->type == 'p')
		printf("--- plane ---\n");
	else
		printf("unknown: %c\n", obj->type);
	printf("translation ");
	print_point(obj->tr_vec);
	print_matrix(obj->transformation);
	printf("main color:      %x\n", obj->colors[0]);
	printf("reflexive color: %x\n", obj->colors[1]);
}

void	print_lights(t_list *lights)
{
	while (lights)
	{
		printf("light:\norigin ");
		print_point(((t_light *)lights->content)->pos);
		printf("color: %x\n", ((t_light *)lights->content)->color);
		printf("ratio: %f\n", ((t_light *)lights->content)->ratio);
		lights = lights->next;
	}
}
