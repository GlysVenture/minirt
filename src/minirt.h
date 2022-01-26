//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef MINIRT_H
# define MINIRT_H

#include "camera.h"
#include "light/light.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef	struct s_mlx_utils
{
	void			*mlx;
	void 			*win;
	t_data			img;
}	t_mlx_utils;

typedef struct s_vars
{
	t_amb_light		*ambient;
	t_adv_camera	*cam;
	t_list			**obj;
	t_list			**lights;
	t_mlx_utils		*mu;
}	t_vars;

void	launch_window(t_list **objects);

#endif //MINIRT_H
