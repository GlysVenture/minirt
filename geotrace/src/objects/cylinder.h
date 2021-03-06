/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:36 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:36 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 2/2/22.
//

#ifndef CYLINDER_H
# define CYLINDER_H

# include "geotrace.h"

double	plane_int0(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal);

double	plane_int1(t_object *cyl, t_line ray, t_vec3d hit, t_vec3d normal);

#endif //CYLINDER_H
