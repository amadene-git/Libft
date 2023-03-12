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

char    *ft_strdup(char const *s)
{
	char	*str;
	char	*strcpy;

	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1))))
        return (NULL);
	strcpy = str;
	while (*s)
		*strcpy++ = *s++;
	*strcpy = '\0';
	return (str);
}
