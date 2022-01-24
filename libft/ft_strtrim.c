/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:10:31 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 14:10:34 by tkondrac         ###   ########.fr       */
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

//finds index of char c in str
static int	ft_findchar(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = (char *)s1;
	while (ft_findchar(set, *start) >= 0)
		start++;
	while (start[i])
		i++;
	if (i == 0)
		return (ft_strdup(""));
	while (ft_findchar(set, start[i - 1]) >= 0)
		i--;
	return (ft_strndup(start, i));
}
