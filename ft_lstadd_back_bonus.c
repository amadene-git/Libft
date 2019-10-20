/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 18:48:33 by admadene          #+#    #+#             */
/*   Updated: 2019/10/12 18:55:25 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (!alst || !*alst)
	{
		*alst = new;
		return ;
	}
	elem = NULL;
	elem = *alst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
}
