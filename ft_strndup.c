/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:57:43 by admadene          #+#    #+#             */
/*   Updated: 2019/10/11 18:03:13 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strndup(const char *s, size_t n)
{
	char	*str;
	char	*strcpy;
    size_t  len;

    len = (n > ft_strlen(s)) ? ft_strlen(s) : n;
	if (!(str = (char*)malloc(sizeof(char) * (len + 1))))
        return (NULL);
	strcpy = str;
	while (*s && n--)
		*strcpy++ = *s++;
	*strcpy = '\0';
	return (str);
}
