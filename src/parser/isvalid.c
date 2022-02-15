/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isvalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:51:33 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/08 18:17:01 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mrt.h"

int	nbrargs(char **args, int nbr)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (0);
	while (args[i] != NULL)
		i++;
	if (i != nbr && (i + 1 == nbr && !ft_strchr(args[i - 1], '\n')))
	{
		printf("Error,wrong number of arguments ");
		printf("have %i expected %i", i, nbr);
		i = -1;
		while (args[++i])
			printf("%s\n", args[i]);
		return (0);
	}
	return (1);
}

void	*error(char *mess, char **tf[2])
{
	int	i;

	i = 0;
	write(2, mess, ft_strlen(mess));
	write(2, "\n", 1);
	while (i != 2)
	{	
		if (tf[i] != NULL)
			free_tab(tf[i]);
		i++;
	}
	return (NULL);
}

int	inrange(t_vec3d v, double min, double max)
{
	int	i;

	i = 0;
	while (i != 3)
	{
		if (isless(v[i], min) != 0 || isgreater(v[i], max) != 0)
			return (0);
		i++;
	}
	return (1);
}
