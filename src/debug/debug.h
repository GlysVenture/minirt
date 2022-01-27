//
// Created by Tadeusz Kondracki on 1/25/22.
//

#ifndef DEBUG_H
# define DEBUG_H

# include "geotrace.h"
#include "libft.h"

void	print_ray(t_line ray);
void	print_point(t_vec3d point);
void	print_objlst(t_list *obj);
void	print_lights(t_list *lights);

#endif //DEBUG_H
