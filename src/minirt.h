//
// Created by Tadeusz Kondracki on 1/26/22.
//

#ifndef MINIRT_H
# define MINIRT_H

typedef struct s_vars
{
	t_amb_light ambient;
	t_adv_cam	cam;
	t_list		**obj;
	t_list		**lights;
	void		*mlx;
	void 		*win;
	t_data		img;
}	t_vars;

#endif //MINIRT_H
