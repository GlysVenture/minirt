//
// Created by tkondrac on 2/2/22.
//

#ifndef CUBE_H
# define CUBE_H

int		get_x_int(double res[], t_line *ray);
int		get_y_int(double res[], t_line *ray);
int		get_z_int(double res[], t_line *ray);
void	add_bounds(double res[], double temp[]);

#endif //CUBE_H
