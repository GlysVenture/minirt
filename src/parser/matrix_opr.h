/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_opr.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:14:52 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 20:18:10 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_OPR_H
# define MATRIX_OPR_H

void	sheer_xy(t_matrix	a, double l);
void	sheer_xz(t_matrix	a, double l);
void	sheer_zy(t_matrix	a, double l);
void	sheer_zx(t_matrix	a, double l);
void	sheer_yz(t_matrix	a, double l);
void	sheer_yx(t_matrix	a, double l);

void	rotate_x(t_matrix m, double a);
void	rotate_y(t_matrix m, double a);
void	rotate_z(t_matrix m, double a);

void	aggr_x(t_matrix m, double a);
void	aggr_y(t_matrix m, double a);
void	aggr_z(t_matrix m, double a);
#endif
