/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:09:01 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/16 12:09:05 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//joins 2 strings and frees first str
char	*ft_strjoin_f(char **s1, char const *s2)
{
	size_t	len;
	char	*join;
	size_t	i;
	size_t	j;

	if (!(*s1) || !s2)
		return (NULL);
	len = ft_strlen(*s1) + ft_strlen(s2);
	join = malloc(sizeof(**s1) * (len + 1));
	if (!join)
		return (NULL);
	i = -1;
	while ((*s1)[++i])
		join[i] = (*s1)[i];
	j = -1;
	while (s2[++j])
		join[i++] = s2[j];
	join[i] = 0;
	free(*s1);
	return (join);
}

//duplicates n characters from string
char	*ft_strndup(const char *src, int len)
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

//string lenght
size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//zero out memory
void	ft_bzero(void *b, size_t n)
{
	while (n-- > 0)
		*(unsigned char *)(b++) = 0;
}
