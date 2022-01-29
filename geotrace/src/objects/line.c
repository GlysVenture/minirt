//
// Created by tkondrac on 22.01.22.
//

#include <math.h>
#include "stdlib.h"

#include "geotrace.h"

/// Creates a new line from a direction and a point
/// \param dir line direction
/// \param p any point of line
/// \return memory allocated [t_line*]
t_line	*init_line(const t_vec3d dir, const t_vec3d p)
{
	t_line	*new;

	new = malloc(sizeof(t_line));
	if (!new)
		return (NULL);
	set_vec(new->direction, dir[0], dir[1], dir[2]);
	set_vec(new->point, p[0], p[1], p[2]);
	return (new);
}
