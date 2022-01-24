/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondrac <tkondrac@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:08:54 by tkondrac          #+#    #+#             */
/*   Updated: 2021/10/14 13:08:58 by tkondrac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*beg;
	void	*content;
	t_list	*new;

	beg = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		if (!content)
		{
			ft_lstclear(&beg, del);
			break ;
		}
		new = ft_lstnew(content);
		if (!new)
		{
			(*del)(content);
			ft_lstclear(&beg, del);
			break ;
		}
		ft_lstadd_back(&beg, new);
		lst = lst->next;
	}
	return (beg);
}
