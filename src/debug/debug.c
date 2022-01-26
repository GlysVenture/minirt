//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "debug.h"
#include "geotrace.h"
#include "libft.h"
#include "object.h"
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
		if (((t_object *)obj->content)->type == 's')
		{
			printf("sphere:\ncenter ");
			print_point(((t_sphere *)((t_object *)obj->content)->structure)->center);
			printf("radius: %f\n", ((t_sphere *)((t_object *)obj->content)->structure)->radius);
		}
		else if (((t_object *)obj->content)->type == 'p')
		{
			printf("plane:\nnormal ");
			print_point(((t_plane *)((t_object *)obj->content)->structure)->normal);
			printf("any ");
			print_point(((t_plane *)((t_object *)obj->content)->structure)->point);
		}
		else
		{
			printf("unknown: %c\n", ((t_object *)obj->content)->type);
		}
		printf("color: %x\n", ((t_object *)obj->content)->color);
		obj = obj->next;
	}
}
