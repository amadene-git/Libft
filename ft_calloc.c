/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:43:50 by admadene          #+#    #+#             */
/*   Updated: 2019/10/12 17:02:47 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
    
	if (nmemb * size < size || nmemb * size < nmemb\
        || (str = malloc(nmemb * size)) == NULL)
        return (NULL);
	ft_bzero(str, (size_t)(nmemb * size));
	return (str);
}
