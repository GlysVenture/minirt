/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:12:14 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 14:12:16 by tkondrac         ###   ########.fr       */
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

static int	ft_split_len(char const *s, char c)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (s[i])
	{
		j = i;
		while (s[i] != c && s[i])
			i++;
		if (i - j > 0)
			len++;
		else
			i++;
	}
	return (len);
}

static int	ft_alloc_error(char ***tab, int k)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < k)
	{
		if ((*tab)[i] == NULL)
			err = 1;
		i++;
	}
	if (!err)
		return (err);
	while (i < k)
	{
		if ((*tab)[i] != NULL)
			free((*tab)[i]);
		i++;
	}
	free(*tab);
	return (err);
}

static void	ft_advance_in_tab(const char *s, char c, int *i)
{
	while (s[*i] != c && s[*i])
		(*i)++;
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	tab = malloc(sizeof(*tab) * (ft_split_len(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		j = i;
		ft_advance_in_tab(s, c, &i);
		if (i - j > 0)
			tab[k++] = ft_strndup(s + j, i - j);
		else
			i++;
	}
	tab[k] = NULL;
	if (ft_alloc_error(&tab, k))
		return (NULL);
	return (tab);
}
