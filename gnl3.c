/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 14:58:41 by ariard            #+#    #+#             */
/*   Updated: 2016/11/20 19:25:05 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int			ft_set_line(char *buf, int size, char **line)
{
	static char		*string;
	char			*tmp;
	char			*tmp2;
	size_t			count;

	(void)line;
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
	printf("string : %s\n", string);
	count = 0;
	while (*string)
	{
		if (*string == 10 || *string == 0)
		{
			printf("string : %s\n", string);
			tmp2 = ft_memalloc(ft_strlen(string));
			ft_bzero(tmp2, ft_strlen(string));
			ft_memcpy(tmp2, string, count);
			string++;
//			printf("tmp2 est de : %s", tmp2);
			*line = tmp2;	
			return (1);
		}
		string++;
		count++;
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
