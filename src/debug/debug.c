//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "debug.h"
#include "geotrace.h"
#include <stdio.h>

void	print_ray(t_line ray)
{
	printf("vector:\npoint\n%f\n%f\n%f\ndir\n%f\n%f\n%f\n", ray.point.x, ray.point.y, ray.point.z, ray.direction.x, ray.direction.y, ray.direction.z);
}

void	print_point(t_vec3d point)
{
	printf("point\n%f\n%f\n%f\n", point.x, point.y, point.z);
}
