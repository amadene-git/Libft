/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:23:16 by admadene          #+#    #+#             */
/*   Updated: 2019/10/11 18:03:30 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *cs1, const char *cs2, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char*)cs1;
	s2 = (char*)cs2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i < n - 1 && s1[i] && s2[i])
	{
		i++;
	}
	if (s1[i] < 0)
		return ((s1[i] + s2[i]) * (-1));
	if (s2[i] < 0)
		return (s1[i] + s2[i]);
	return (s1[i] - s2[i]);
}
