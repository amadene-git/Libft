/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:28:26 by admadene          #+#    #+#             */
/*   Updated: 2019/10/16 17:45:52 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_count(char *str, char charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (!(str[i] != charset) && str[i])
			i++;
		if ((str[i] != charset))
			count++;
		while ((str[i] != charset) && str[i])
			i++;
	}
	if (!(str[i - 1] != charset))
		count--;
	return (count);
}

static int		ft_word_len(char *str, char charset)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (!(str[i] != charset) && str[i])
		i++;
	while ((str[i] != charset) && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

static char		**tab_null(void)
{
	char		**tab;

	if (!(tab = (char**)malloc(sizeof(char*))))
		return (NULL);
	tab[0] = NULL;
	return (tab);
}

char			**ft_split(char const *str, char charset)
{
	char	**tab;
	char	*strcp;
	int		i;
	int		j;

	if (!str)
		return (tab_null());
	strcp = (char*)str;
	tab = malloc(sizeof(char*) * (ft_word_count(strcp, charset) + 1));
	i = 0;
	while (ft_word_count(strcp, charset) > 0)
	{
		j = 0;
		while (!(*strcp != charset) && *strcp)
			strcp++;
		tab[i] = malloc(sizeof(char) * (ft_word_len(strcp, charset) + 1));
		while ((*strcp != charset) && *strcp)
			tab[i][j++] = *strcp++;
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
