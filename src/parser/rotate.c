/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:33:48 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 19:34:20 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include "parse.h"
#include "minirt.h"

void	rotate_x(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = cos(a);
	b[1][2] = (sin(a) * -1);
	b[2][1] = sin(a);
	b[2][2] = cos(a);
	matrix_prod(m, b, m);
}

void	rotate_y(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = cos(a);
	b[0][2] = sin(a);
	b[1][1] = 1;
	b[2][0] = (sin(a) * -1);
	b[2][2] = cos(a);
	matrix_prod(m, b, m);
}

void	rotate_z(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = cos(a);
	b[0][1] = (sin(a) * -1);
	b[1][0] = sin(a);
	b[1][1] = cos(a);
	b[2][2] = 1;
	matrix_prod(m, b, m);
}
