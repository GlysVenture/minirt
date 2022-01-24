/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:10:35 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 14:10:39 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//duplicates len characters from string
static char	*ft_strndup(const char *src, int len)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(*src) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(dup + i) = src[i];
		i++;
	}
	*(dup + i) = 0;
	return (dup);
}

//duplicates substring of at most len characters
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) - start > len)
		return (ft_strndup(s + start, len));
	else
		return (ft_strdup(s + start));
}
