//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef PARSE_H
# define PARSE_H

#include "minirt.h"

int	parse_sphere(char *line, t_vars *v);
int	parse_plane(char *line, t_vars *v);
int	parse_light(char *line, t_vars *v);
//int parse_cylinder(char *line, t_vars *v);
int	parse_object(char *line, t_vars *v);
#endif //PARSE_H
