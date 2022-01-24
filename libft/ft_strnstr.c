/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:53:23 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:53:31 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//find first occurence of string needle in haystack
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*pos;
	size_t	n;
	size_t	i;

	n = ft_strlen(needle);
	pos = (char *)haystack;
	if (*needle == 0)
		return (pos);
	i = 0;
	while (*pos && i + n <= len)
	{
		if (!ft_strncmp(pos, needle, n))
			return (pos);
		pos++;
		i++;
	}
	return (NULL);
}
