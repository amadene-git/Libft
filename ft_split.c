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

static char    **ft_split_rec(char const *str, char charset, int lvl)
{
    char **tab;
    int i;

    tab = NULL;
    i = 0;
    while (*str == charset && *str)
        str++;
    while (str[i] != charset && str[i])
        i++;
    if (!*str)
    {
        tab = malloc(sizeof(char*) * (lvl + 1));
        tab[lvl] = NULL;
        return (tab);
    }
    else
    {
        tab = ft_split_rec(str + i, charset, lvl + 1);
        tab[lvl] = ft_strndup(str, i);
    }
    return (tab);
}



char    **ft_split(char const *str, char charset)
{
    if (!str)
        return (NULL);
    return (ft_split_rec(str, charset, 0));
}
