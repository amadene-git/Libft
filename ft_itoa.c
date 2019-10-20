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

#include <stdlib.h>

static	int		ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	char	*ft_strrev(char *str)
{
	char	rev[ft_strlen(str)];
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (str[++i])
		rev[i] = str[i];
	i--;
	while (i + 1)
		str[j++] = rev[i--];
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		signe;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * 12)))
		return (NULL);
	if (n == -2147483648)
		return ("-2147483648");
	if (n == 0)
		return ("0");
	if ((signe = 1) && n < 0)
	{
		signe = 0;
		n *= -1;
	}
	while (n)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (!signe)
		str[i++] = '-';
	str[i] = '\0';
	return (ft_strrev(str));
}
