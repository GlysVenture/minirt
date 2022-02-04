/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_opr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:33:42 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 20:18:44 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"
#include "parse.h"
#include "minirt.h"
#include "matrix_opr.h"

void	ft_sheer(char *dir, t_matrix m, double l)
{
	if (!ft_strncmp(dir, "xy", 3))
		sheer_xy(m, l);
	else if (!ft_strncmp(dir, "xz", 3))
		sheer_xz(m, l);
	else if (!ft_strncmp(dir, "yz", 3))
		sheer_yz(m, l);
	else if (!ft_strncmp(dir, "yx", 3))
		sheer_yx(m, l);
	else if (!ft_strncmp(dir, "zx", 3))
		sheer_zx(m, l);
	else if (!ft_strncmp(dir, "zy", 3))
		sheer_zy(m, l);
}

void	ft_rotate(char dir, t_matrix m, double l)
{
	if (dir == 'x')
		rotate_x(m, radians(l));
	else if (dir == 'y')
		rotate_y(m, radians(l));
	else if (dir == 'z')
		rotate_z(m, radians(l));
}

void	ft_aggr(char dir, t_matrix m, double l)
{
	if (dir == 'x')
		aggr_x(m, l);
	else if (dir == 'y')
		aggr_y(m, l);
	else if (dir == 'z')
		aggr_z(m, l);
}
