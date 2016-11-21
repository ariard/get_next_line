/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:17:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 23:20:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static int			ft_check_buf(char *buf)
{
	while (*buf)
	{
		if (*buf == 10)
			return (1);
		buf++;
	}
	return (0);
}

static char			*ft_set_string(char *buf, char *string, int size)
{
	if (!string)
		string = ft_memalloc(size);
//	printf("buf : %s\n", buf);
	ft_strncat(string, buf, size);
	free(buf);
	return (string);
}

static size_t		ft_set_line(char *string, char **line)
{
	char			*tmp;

	tmp = string;
	while (*string != 10 && *string != 0)
		string++;
	*string = '\0';
	*line = tmp;
//	printf("line : %s\n", *line);
	return (ft_strlen(tmp) + 1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*string;
	t_gnl			gnl;	

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	gnl.check = 0;
	gnl.ret = 1;
	while (gnl.check == 0 && gnl.ret > 0)
	{
		gnl.buf = ft_memalloc(BUFF_SIZE);
		gnl.ret = read(fd, gnl.buf, BUFF_SIZE);
		string = ft_set_string(gnl.buf, string, BUFF_SIZE);
		gnl.check = ft_check_buf(gnl.buf);
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
