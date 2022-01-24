/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 11:59:57 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 12:00:01 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*needle;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	needle = *lst;
	while (needle->next)
	{
		needle = needle->next;
	}
	needle->next = new;
}
