/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgyger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:32:16 by lgyger            #+#    #+#             */
/*   Updated: 2022/02/04 17:33:37 by lgyger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	free_tab(char **tab)
{
	char	**s;

	if (tab == NULL)
		return (0);
	s = tab;
	while (*s)
		free(*(s++));
	free(tab);
	tab = NULL;
	return (0);
}
