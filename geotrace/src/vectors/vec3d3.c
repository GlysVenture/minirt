/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3d3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:56:41 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 18:56:41 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by tkondrac on 2/2/22.
//

#include <stdio.h>

#include "geotrace.h"

/// prints a vector to STDOUT
/// \param point vector
void	print_point(t_vec3d point)
{
	printf("point\n%f\n%f\n%f\n", point[0], point[1], point[2]);
}
