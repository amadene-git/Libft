/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admadene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:17 by admadene          #+#    #+#             */
/*   Updated: 2019/11/29 14:59:05 by admadene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*str;
	int		len;
	char	*cpy;

	if (!s1 && s2)
		return (ft_strdup(s2));
	if (!s2 && s1)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	cpy = s1;
	len = ft_strlen((char*)s1) + ft_strlen((char*)s2);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (*s1)
		*str++ = *s1++;
	while (*s2)
		*str++ = *s2++;
	*str = '\0';
	free(cpy);
	return (str - len);
}

static int		get_current_line(int fd, char **save)
{
	char	buffer[BUFFER_SIZE + 1];
	int		ret;

	ret = 1;
	while (ret && !ft_strchr(*save, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret > 0)
		{
			buffer[ret] = 0;
			if (!(*save = ft_strjoinfree(*save, buffer)))
				return (0);
		}
	}
	if (!*save)
		*save = ft_strdup("");
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char		*save[1024];
	char			*tmp;

	if (read(fd, NULL, 0) == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	if (!get_current_line(fd, &save[fd]))
		return (-1);
	tmp = save[fd];
	if (ft_strchr(save[fd], '\n'))
	{
		if (!(*line = ft_substr(save[fd], \
		0, (ft_strchr(save[fd], '\n') - save[fd]))))
			return (-1);
		if (!(save[fd] = ft_strdup(ft_strchr(save[fd], '\n') + 1)))
			return (-1);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	if (!(*line = ft_strdup(save[fd])))
		return (-1);
	free(tmp);
	save[fd] = NULL;
	return (0);
}
