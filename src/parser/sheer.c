/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sheer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:13:58 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 19:20:57 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include "parse.h"
#include "minirt.h"

void	sheer_xy(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof (t_matrix));
	b[0][0] = 1;
	b[0][1] = l;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(a, b, a);
}

void	sheer_yx(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][0] = l;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(a, b, a);
}

void	sheer_xz(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[0][2] = l;
	b[2][2] = 1;
	matrix_prod(a, b, a);
}

void	sheer_zx(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[2][0] = l;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(a, b, a);
}

void	sheer_zy(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b, 0, sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[2][2] = 1;
	b[2][1] = l;
	matrix_prod(a, b, a);
}
