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

# include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    int     i;
 
    if (!s1)
        return (ft_strdup(""));
    if (!*s1 || !set)
        return (ft_strdup(s1));
    while (ft_strchr(set, *s1) && *s1)
        s1++;
    i = 0;
    while (!ft_strchr(set, s1[i]) && s1[i])
        i++;
    return (ft_strndup(s1, i));
}
