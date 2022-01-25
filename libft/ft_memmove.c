/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:23:26 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:23:28 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	int		rev;

	i = 0;
	rev = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		if (src + i == dst)
			rev = 1;
		i++;
	}
	if (rev)
	{
		i = 1;
		while (i <= n)
		{
			*(unsigned char *)(dst + n - i) = *(unsigned char *)(src + n - i);
			i++;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, n));
}
