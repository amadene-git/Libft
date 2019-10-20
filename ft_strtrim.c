/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:50:45 by admadene          #+#    #+#             */
/*   Updated: 2019/10/16 17:18:22 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup(char const *s)
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

static int	check_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (0);
		set++;
	}
	return (1);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*strcpy;

	if (!s1)
		return (ft_strdup(""));
	if (!*s1 || !set)
		return (ft_strdup(s1));
	str = ft_strdup(s1);
	while (!check_set(*str, set))
		*str++ = '\0';
	strcpy = str;
	while (*str)
		str++;
	str--;
	while (!check_set(*str, set))
		*str-- = '\0';
	return (strcpy);
}
