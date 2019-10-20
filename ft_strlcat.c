/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:57:24 by admadene          #+#    #+#             */
/*   Updated: 2019/10/15 12:42:25 by admadene         ###   ########.fr       */
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

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*s;
	char	*d;
	int		lentotal;

	lentotal = ft_strlen(dest) + ft_strlen((char const *)src);
	s = (char*)src;
	d = dest;
	if (size < (size_t)ft_strlen(dest))
		return (ft_strlen((char*)src) + size);
	while (*d)
	{
		d++;
		size--;
	}
	if (!size)
		return (ft_strlen(dest) + ft_strlen((const char *)src));
	while (--size && *s)
	{
		*d++ = *s++;
		if (size == 0)
			return (0);
	}
	*d = '\0';
	return (lentotal);
}
