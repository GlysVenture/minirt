/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:01:09 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 14:01:11 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoa_len(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (len);
}

//int to string
char	*ft_itoa(int n)
{
	char		*numb;
	long int	temp;
	int			len;

	len = ft_itoa_len(n);
	numb = malloc(sizeof(char) * (len + 1));
	if (!numb)
		return (NULL);
	temp = n;
	if (temp < 0)
		temp = -temp;
	numb[len] = 0;
	while (temp / 10)
	{
		numb[--len] = (temp % 10) + 48;
		temp /= 10;
	}
	numb[--len] = (temp % 10) + 48;
	if (len)
		*numb = '-';
	return (numb);
}
