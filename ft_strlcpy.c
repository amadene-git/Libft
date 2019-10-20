/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:02:24 by admadene          #+#    #+#             */
/*   Updated: 2019/10/11 18:03:20 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	int	ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t		ft_strlcpy(char *dest, const char *src, size_t size)
{
	const	char	*strcp;

	strcp = src;
	if (size <= 0)
		return (ft_strlen((char*)src));
	while (--size && *strcp)
		*dest++ = *strcp++;
	*dest = '\0';
	return (ft_strlen((char*)src));
}
