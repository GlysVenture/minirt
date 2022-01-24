/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:45:46 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:45:48 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//locate last occurence of character in string
char	*ft_strrchr(const char *s, int c)
{
	char	*loc;
	int		i;

	loc = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			loc = (char *)s + i;
		i++;
	}
	if (c == 0)
		loc = (char *)s + i;
	return (loc);
}
