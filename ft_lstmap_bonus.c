/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 19:05:33 by admadene          #+#    #+#             */
/*   Updated: 2019/10/15 12:47:28 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_list	*ft_static_lstnew(void *content)
{
	t_list *elem;

	elem = (t_list*)malloc(sizeof(t_list));
	elem->next = NULL;
	elem->content = content;
	return (elem);
}

static	void	ft_static_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	elem = *alst;
	if (!elem)
	{
		elem = new;
		return ;
	}
	while (elem->next)
		elem = elem->next;
	elem->next = new;
}

t_list			*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	**begin_list;
	t_list	*elem;

	begin_list = NULL;
	if (lst)
	{
		*begin_list = ft_static_lstnew(f(lst->content));
		lst = lst->next;
	}
	while (lst)
	{
		elem = ft_static_lstnew(f(lst->content));
		ft_static_lstadd_back(begin_list, elem);
		lst = lst->next;
	}
	return (*begin_list);
}
