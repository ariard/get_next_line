/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:21:54 by ariard            #+#    #+#             */
/*   Updated: 2016/11/26 17:49:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int				get_next_line(const int fd, char **line)
{
	static char	*stock;
	char		*tmp;
	char		*tmp2;
	char		*tmp3;
	char		*string;
	t_gnl		gnl;

	if (fd < 0 || line == NULL || BUFF_SIZE <=0)
		return (-1);
	if (stock == NULL)
	{
		stock = ft_strnew(BUFF_SIZE);
		string = ft_strnew(BUFF_SIZE);
	}
	else
		string = stock;
	ft_memset(gnl.buf, 0, BUFF_SIZE + 1);
	while ((gnl.ret = read(fd, gnl.buf, BUFF_SIZE)) > 0)
	{
		tmp = string;
		string = ft_strnew(ft_strlen(gnl.buf) + ft_strlen(tmp));
		ft_strcpy(string, tmp);
		ft_strcat(string, gnl.buf);
		ft_strdel(&tmp);
		ft_memset(gnl.buf, 0, BUFF_SIZE + 1);
	}
	if (*string && gnl.ret >= 0)
	{
		tmp2 = string;
		tmp3 = stock;
		while (*string != 10 && *string != 0) 
			string++;
		*string = '\0';
		*line = tmp2;
		string++;
		stock = string;
		return (1);
	}
	return (gnl.ret);
}
