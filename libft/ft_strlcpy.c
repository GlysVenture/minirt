/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:45:37 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:45:41 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size-bounded string copying
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*(src + i) != '\0' && i + 1 < size)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size != 0)
		*(dest + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}
