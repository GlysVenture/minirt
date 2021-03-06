/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 19:38:16 by tkondrac          #+#    #+#             */
/*   Updated: 2022/02/07 19:38:16 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by Tadeusz Kondracki on 1/25/22.
//

#ifndef KEY_HANDLER_H
# define KEY_HANDLER_H

# include "minirt.h"

# ifdef __gnu_linux__

enum e_key
{
	key_esc = 65307
};

# endif

# ifdef __APPLE__

enum e_key
{
	key_esc = 53
};

# endif

int	key_handler(int keycode, t_vars *v);
int	ftquit(t_vars *v);

#endif //KEY_HANDLER_H
