/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 20:10:09 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 20:10:45 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geotrace.h"
#include "../camera.h"
#include "libft.h"
#include "../object.h"
#include "mrt.h"
#include "light/light.h"

void	tr_free(t_object *obj, char **tf[2])
{
	if (tf != NULL)
	{
		free_tab(tf[0]);
		if (tf[1] != NULL)
			free_tab(tf[1]);
	}
	inverse_matrix(obj->transformation, obj->inv);
	matrix_transpose(obj->inv, obj->inv_transp);
}

void	set_default(t_object **obj, char name)
{
	*obj = init_object(name);
	(*obj)->colors[1] = 0xFFFFFF;
	(*obj)->k_ratio[0] = 0.1;
	(*obj)->k_ratio[1] = 0.7;
	(*obj)->k_ratio[2] = 0.2;
	set_id_matrix((*obj)->transformation);
}
