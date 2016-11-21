/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:17:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 16:02:35 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

static	int			ft_check_buf(char *buf)
{
	while (*buf)
	{
		if (*buf == 10 || *buf == 0)
			return (1);
		buf++;
	}
	return (0);
}

static char			*ft_set_string(char *buf, char *string, int size)
{
	if (!string)
		string = ft_memalloc(BUF_SIZE);
	ft_strncat(string, buf, size);	
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
	printf("line : %s", *line);
	return (ft_strlen(tmp) + 1);
}

int					get_next_line(const int fd, char **line)
{
	int				ret;
	int 			check;
	char			buf[BUF_SIZE];
	static char		*string;
	size_t			len;

	check = 0;
	ret = 1;
	ft_bzero(buf, BUF_SIZE);
	while (check == 0 && ret > 0)
	{
		ret = read(fd, buf, BUF_SIZE);
		string = ft_set_string(buf, string, BUF_SIZE);
		check = ft_check_buf(buf);
		ft_bzero(buf, BUF_SIZE);
	}
	if (*string)
	{
		len = ft_set_line(string, line);
		while (len--)
			string++;
		return (1);
	}
	return (ret);
}
