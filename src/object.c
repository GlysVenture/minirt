//
// Created by Tadeusz Kondracki on 1/24/22.
//

#include <stdlib.h>

#include "object.h"
#include "debug/debug.h"

/*t_object	*init_obj(char c, void *struc, int color)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->structure = struc;
	new->type = c;
	new->color = color;
	return (new);
}

void	set_obj(t_object *obj, char c, void *struc, int color)
{
	obj->color = color;
	obj->type = c;
	obj->structure = struc;
}*/

void	destroy_obj(t_object *obj)
{
	if (obj->params != NULL)
		free(obj->params);
	free(obj);
}
