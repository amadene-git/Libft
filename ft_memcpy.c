/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:51:02 by admadene          #+#    #+#             */
/*   Updated: 2019/10/11 18:02:50 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned	const	char	*s;
	unsigned	char			*d;

	s = (unsigned const char*)src;
	d = (unsigned char*)dest;
	if (!dest && !src)
		return (NULL);
	while (n && n--)
		*d++ = *(unsigned char*)s++;
	return (dest);
}
