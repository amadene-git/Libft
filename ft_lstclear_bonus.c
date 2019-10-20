/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:58:35 by admadene          #+#    #+#             */
/*   Updated: 2019/10/12 18:15:46 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*elem;
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	elem = NULL;
	elem = *lst;
	while (elem)
	{
		tmp = elem;
		elem = elem->next;
		del(tmp->content);
		free(tmp);
	}
	*lst = 0;
}
