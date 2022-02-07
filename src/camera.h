/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:38:16 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:38:16 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/24/22.
//

#ifndef CAMERA_H
# define CAMERA_H

# include "geotrace.h"

typedef struct s_camera
{
	t_vec3d	origin;
	t_vec3d	direction;
	double	angle;
}	t_camera;

typedef struct s_adv_camera
{
	t_camera	cam;
	t_vec3d		horizontal;
	t_vec3d		vertical;
}	t_adv_camera;

void	set_advanced_camera(t_adv_camera *cam, int x, int y, t_line *ray);

#endif //CAMERA_H
