/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:17:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/24 14:26:39 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char			*ft_set_string(char *buf, char *string, int size)
{
	if (!string)
		string = ft_memalloc(size);
	ft_strncat(string, buf, size);
	free(buf);
	return (string);
}

static size_t		ft_set_line(char *string, char **line)
{
	char			*tmp;

	tmp = string;
	if (*string == 10 && *(string - 1) == 0)
	{
		*string = '\0';
		return (1);
	}
	while (*string != 10 && *string != 0)
		string++;
	*string = '\0';
	*line = tmp;
	return (ft_strlen(tmp) + 1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*string;
	t_gnl			gnl;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	gnl.check = NULL;
	gnl.ret = 1;
	while (gnl.check == NULL && gnl.ret > 0)
	{
		gnl.buf = ft_memalloc(BUFF_SIZE);
		gnl.ret = read(fd, gnl.buf, BUFF_SIZE);
		string = ft_set_string(gnl.buf, string, BUFF_SIZE);
		gnl.check = ft_strchr(gnl.buf, 10);
	}
	if (*string)
	{
		gnl.len = ft_set_line(string, line);
		while (gnl.len--)
			string++;
		return (1);
	}
	return (gnl.ret);
}
