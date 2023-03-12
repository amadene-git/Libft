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


#include "libft.h"

char	*ft_strjoindoublefree(char *s1, char *s2)
{
	char	*str;
	int		len;
	char	*cpy;
	char	*cpy2;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	cpy = s1;
	cpy2 = s2;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(cpy2);
	free(cpy);
	return (str - len);
}

