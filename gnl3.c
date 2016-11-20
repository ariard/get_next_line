/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:58:41 by ariard            #+#    #+#             */
/*   Updated: 2016/11/20 17:48:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


static int			ft_set_line(char *string, char **line)
{
	char			*tmp;

	tmp

static int			ft_set_string(char *buf, int size, char **line)
{
	static char		*string;
	char			*tmp;

	if (!string)
	{
		string = ft_memalloc(size);
		ft_bzero(string, size);
	}
	tmp = ft_memalloc(ft_strlen(string));
	ft_memcpy(tmp, string, ft_strlen(string));
	string = ft_memalloc(ft_strlen(string) + size);
	ft_memcpy(string, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
	ft_strncat(string, buf, size);
	while (size--)
	{
		if (*buf == 10 || *buf == 0)
		{
			*line = string;
			ft_strdel(&string);
			return (1);
		}
		buf++;
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUF_SIZE];

	(void)line;
	ret = 1;
	ft_bzero(buf, BUF_SIZE);
	while (ret > 0)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ft_set_line(buf, BUF_SIZE, line))
			return (1);
		ft_bzero(buf, BUF_SIZE);
	}
	return (ret);
}
