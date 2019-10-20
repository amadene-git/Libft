/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:59:44 by admadene          #+#    #+#             */
/*   Updated: 2019/10/16 17:17:42 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int		ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	char	*ft_strdup(char const *s)
{
	char	*str;
	char	*strcpy;

	str = (char*)malloc(sizeof(char) * (ft_strlen((char*)s) + 1));
	if (str == NULL)
		return (NULL);
	strcpy = str;
	while (*s)
		*strcpy++ = *s++;
	*strcpy = '\0';
	return (str);
}

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*str;
	unsigned	int		i;

	i = 0;
	if (!f && s)
		return (ft_strdup((char*)s));
	if (!s)
		return (NULL);
	str = ft_strdup((char*)s);
	if (str == NULL)
		return (NULL);
	while (*str)
		*str++ = f(i++, *(char*)s++);
	return (str - i);
}
