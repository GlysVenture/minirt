/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sheer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:25:22 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 19:25:24 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include "parse.h"
#include "minirt.h"

void	sheer_yz(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[2][2] = 1;
	b[1][2] = l;
	matrix_prod(a, b, a);
}
