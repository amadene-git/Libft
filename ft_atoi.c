/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:33:49 by admadene          #+#    #+#             */
/*   Updated: 2019/10/15 09:43:13 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_atoi(const char *str)
{
	int i = 0;
	int res = 0;
	int sign;

	while (ft_isspace(*(str + i)))
		i++;
	sign = (*(str + i) == '-') ? -1 : 1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (ft_isdigit(*(str + i)))
	{
		res = (res * 10) + ((*(str + i) - '0') * sign);
		i++;
	}
	return (res);
}
