/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:03:04 by admadene          #+#    #+#             */
/*   Updated: 2019/10/18 18:22:59 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa_rec(long int i, int *lvl, int sign)
{
    char *str;

    (*lvl)++;
    str = NULL;
    if (i > 0)
    {
        str = ft_itoa_rec(i / 10, lvl, sign);
        str[*lvl] = i % 10 + '0';
        (*lvl)++;        
        return (str);
    }
    else
    {
        str = malloc(*lvl + 1 + sign);
        str[*lvl + sign] = '\0';
        if (sign)
        {
            *lvl = 1;
            str[0] = '-';
        }
        else
            *lvl = 0;
        return (str);
    }
}

char    *ft_itoa(int n)
{
    long int i;
    int lvl;

    if (n == 0)
        return (ft_strdup("0"));
    lvl = -1;
    i = (long int)n;
    return (ft_itoa_rec((n < 0) ? -i : i, &lvl, (n < 0)));
}

