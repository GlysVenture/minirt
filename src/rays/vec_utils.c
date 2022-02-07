/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:05:16 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 20:05:16 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/26/22.
//

#include <math.h>

#include "vec_utils.h"
#include "geotrace.h"

double	cos_angle(const t_vec3d u, const t_vec3d v)
{
	return (dot_prod(u, v) / (vec_norm(v) * vec_norm(u)));
}
