/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:41:24 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:41:24 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/25/22.
//

#ifndef DEBUG_H
# define DEBUG_H

# include "geotrace.h"
# include "libft.h"
# include "object.h"

void	print_objlst(t_list *obj);
void	print_lights(t_list *lights);
void	print_obj(t_object *obj);

#endif //DEBUG_H
