/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:58:41 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 15:52:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static size_t		ft_set_line(char *string, char **line)
{
	char			*tmp1;
	
	tmp1 = ft_memalloc(ft_strlen(string)); 
	tmp1 = string;
	while (*string != 10 && *string != 0)
		string++;	
	*string = '\0';
	*line = tmp1;
	printf("line : %s\n", *line);
	return (ft_strlen(tmp1) + 1);
}

static int			ft_set_string(char *string, char *buf, int size, char **line)
{
	char			*tmp;
	size_t			len;

	tmp = ft_memalloc(ft_strlen(string));
	ft_memcpy(tmp, string, ft_strlen(string));
	string = ft_memalloc(ft_strlen(string) + size);
	ft_memcpy(string, tmp, ft_strlen(tmp));
	ft_strdel(&tmp);
	ft_strncat(string, buf, size);
//	printf("string : %s\n", string);
	while (*buf)
	{
		if ((*buf == 10 || *buf == 0) && *string)
		{
			len = ft_set_line(string, line);
			while (len--)
				string++;
//			printf("s : %s\n", string);
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
	static char		*string;

	if (!string)
	{
		string = ft_memalloc(BUF_SIZE);
		ft_bzero(string, BUF_SIZE);
	}
	ret = 1;
	ft_bzero(buf, BUF_SIZE);
	while (ret > 0 || *string)
	{
		ret = read(fd, buf, BUF_SIZE);
		if (ft_set_string(string, buf, BUF_SIZE, line))
			return (1);
		ft_bzero(buf, BUF_SIZE);
	}
	return (ret);
}
