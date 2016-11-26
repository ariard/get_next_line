/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:17:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/26 20:22:57 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*ft_set(char *buf, char *string)
{
	char			*tmp;

	tmp = string;
	string  = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (string);
}

static t_gnl				ft_set_string(char *stock, const int fd)
{
		t_gnl			gnl;
	
		gnl.check = NULL;
		gnl.ret = 1;
		gnl.string = ft_strdup(stock);
		while (gnl.check == NULL && gnl.ret > 0)
		{
			ft_memset(gnl.buf, 0, BUFF_SIZE + 1);
			gnl.ret = read(fd, gnl.buf, BUFF_SIZE);
			gnl.buf[BUFF_SIZE] = '\0';	
			gnl.string = ft_set(gnl.buf, gnl.string);	
			gnl.check = ft_strchr(gnl.buf, 10);
		}
		return (gnl);
}

static int			ft_set_line(char **line, char *string)
{
		char		*tmp2;
		char		*tmp3;
		int 		last;

		*line = ft_memalloc(sizeof(char));
		tmp2 = *line;	
		tmp3 = string;	
		while (*string != 10  && *string)
			string++;
		last = 0;
		if (*string == 0)
			last++;
		*string = '\0';
		*line = tmp3;
		ft_strdel(&tmp2);
		return (last);
}

int					get_next_line(const int fd, char **line)
{
	static char		*stock;
	char			*tmp;
	char			*string;
	int				last;
	t_gnl			gnl;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!stock)
		stock = ft_strnew(0); 
	gnl = ft_set_string(stock, fd);
	string = gnl.string;
	if (*string)  
	{
		last = ft_set_line(line, string);
		while (*string != 10 && *string)
			string++;
		*string = '\0';
		string++;
		if (*string && last == 0)
		{
			tmp = stock;
			stock = ft_strdup(string);
			ft_strdel(&tmp);
		}
		else
			ft_strdel(&stock);
		return (1);
	}
	return (gnl.ret);
}
