/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:13:31 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 20:14:09 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include "parse.h"
#include "minirt.h"

void	aggr_x(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = a;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(m, b, m);
}

void	aggr_y(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = a;
	b[2][2] = 1;
	matrix_prod(m, b, m);
}

void	aggr_z(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[2][2] = a;
	matrix_prod(m, b, m);
}
