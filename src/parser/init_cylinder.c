#include "mrt.h"

t_cylinder *init_cylinder(double cx,double cy, double cz,t_vec3d or,double height, double diameter)
{
	t_cylinder *new;

	new = malloc(sizeof(t_cylinder));
	if (!new)
		return (NULL);
	new->orient[0] = or[0];
	new->orient[1] = or[1];
	new->orient[2] = or[2];
	new->center[0] = cx;
	new->center[1] = cy;
	new->center[2] = cz;
	new->height = height;
	new->diameter = diameter;
	return (new);
}
