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

static int  isInCharset(char c, const char *charset)
{
    if (charset == NULL)
        return (0);
    while (*charset)
    {
        if (*charset == c)
            return (1);
        ++charset;
    }
    return (0);
}     

static char    **recursiveSplit(char const *str, const char *charset, int lvl)
{
    char **tab;
    int i;

    tab = NULL;
    i = 0;
    while (str[i] && isInCharset(*str, charset))
        str++;
    while (str[i] && !isInCharset(str[i], charset))
        i++;
    if (!*str)
    {
        tab = malloc(sizeof(char*) * (lvl + 1));
        tab[lvl] = NULL;
        return (tab);
    }
    else
    {
        tab = recursiveSplit(str + i, charset, lvl + 1);
        tab[lvl] = ft_strndup(str, i);
    }
    return (tab);
}

char    **ft_split_charset(char const *str, const char *charset)
{
    if (!str)
        return (NULL);
    return (recursiveSplit(str, charset, 0));
}



char    **ft_split(char const *str, char c)
{
    char charset[2] = {c, '\0'};
    if (!str)
        return (NULL);
    return (recursiveSplit(str, charset, 0));
}
