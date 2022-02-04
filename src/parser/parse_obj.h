/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:30:16 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 20:09:30 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_OBJ_H
# define PARSE_OBJ_H
# include "mrt.h"
# include "parse.h"
# include "minirt.h"

int			parse_object(char *line, t_vars *v);
int			parse_matrix(t_object *obj, char **args);
void		parse_int_matrix(t_matrix matrix, char *name, char *args);
void		parse_colors(t_object *obj, char **args);
int			hexcolor(char *line);
void		tr_free(t_object *obj, char **tf[2]);

#endif
