/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:47:23 by admadene          #+#    #+#             */
/*   Updated: 2019/10/16 17:39:05 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

    if (!s || start >= ft_strlen(s))
        return (ft_strdup(""));
    if (len > ft_strlen(s) - start)
        len = ft_strlen(s) - start;
    if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
    i = 0;
    s += start;
    while (i++ < len && *s)
        *str++ = *s++;
    *str = '\0';
    return (str - i + 1);
}
