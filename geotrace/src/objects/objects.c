//
// Created by Tadeusz Kondracki on 1/31/22.
//

#include <stdlib.h>

#include "geotrace.h"

t_object	*init_object(char type)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	return (new);
}
