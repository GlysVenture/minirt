/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:45:42 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:45:45 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//size-bounded string concatenation
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	m;

	i = 0;
	m = 0;
	while (*(dest + m))
		m++;
	while ((i + 1 + m) < size && *(src + i))
	{
		*(dest + m + i) = *(src + i);
		i++;
	}
	if ((m + 1) <= size)
		*(dest + m + i) = 0;
	while (*(src + i))
		i++;
	if (size < m)
		return (size + i);
	return (m + i);
}
