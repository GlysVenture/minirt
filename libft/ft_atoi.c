/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:53:07 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:53:09 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//transform string into int
int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	numb;

	i = 0;
	numb = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		sign = sign * -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		numb = 10 * numb + (str[i] - '0');
		i++;
	}
	return (sign * numb);
}
