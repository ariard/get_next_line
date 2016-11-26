/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:17:15 by ariard            #+#    #+#             */
/*   Updated: 2016/11/26 18:51:34 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char			*ft_set_string(char *buf, char *string)
{
	char			*tmp;

	tmp = string;
	string  = ft_strjoin(tmp, buf);
	ft_strdel(&tmp);
	return (string);
}

/*static size_t		ft_set_line(char *string, char **line)
{
	char			*tmp;

	tmp = string;
	while (*string != 10 && *string != 0)
		string++;
	*string = '\0';		
	*line = tmp;
	return (ft_strlen(tmp) + 1);
}*/

int					get_next_line(const int fd, char **line)
{
	static char		*stock;
	char			*tmp2;
	char			*tmp;
	char			*tmp3;
	char			*string;
	int				last;
	t_gnl			gnl;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	gnl.check = NULL;
	gnl.ret = 1;
	if (!stock)
		stock = ft_strnew(0);
	string = ft_strdup(stock);
	while (gnl.check == NULL && gnl.ret > 0)
	{
		ft_memset(gnl.buf, 0, BUFF_SIZE + 1);
		gnl.ret = read(fd, gnl.buf, BUFF_SIZE);
		gnl.buf[BUFF_SIZE] = '\0';	
		string = ft_set_string(gnl.buf, string);	
		gnl.check = ft_strchr(gnl.buf, 10);
	}
	if (*string)  
	{
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
		string++;
		if (*string && last == 0)
		{
			tmp = stock;
			stock = ft_strdup(string);
			ft_strdel(&tmp);
		}
		else
			ft_strdel(&stock);
		ft_strdel(&tmp2);
		return (1);
	}
	return (gnl.ret);
}
