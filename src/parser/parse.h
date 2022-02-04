/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:58:47 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 18:59:31 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "minirt.h"

int	parse_sphere(char *line, t_vars *v);
int	parse_plane(char *line, t_vars *v);
int	parse_light(char *line, t_vars *v);
int	parse_cylinder(char *line, t_vars *v);
int	parse_object(char *line, t_vars *v);
int	parse_camera(char *line, t_camera *cam);
#endif
