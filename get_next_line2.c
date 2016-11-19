/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 21:10:58 by ariard            #+#    #+#             */
/*   Updated: 2016/11/20 00:30:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void		ft_set_line(char **line, char *s)
{
	char 	*new_tmp;
	char	*keep;
	char	*keep2;

	keep = ft_memalloc(ft_strlen(s));
	keep2 = ft_memalloc(ft_strlen(s));
	new_tmp = ft_memalloc(ft_strlen(s));
	keep = new_tmp;
	keep2 = s;
	while (*s != 10 && *s != '\0')
	{
		*new_tmp = *s;
		new_tmp++;
		s++;
	}
	s++;
	*new_tmp = '\0';
	*line = keep;
	ft_memmove(keep2, s, ft_strlen(s));
//	printf("%s", *line);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUF_SIZE];
	static char	*tmp;
	char		*tmp2;
	char		*tmp3;

	if (fd == -1)
		return (-1);
	if (!tmp)	
	{
	ft_bzero(buf, BUF_SIZE);
	tmp = ft_memalloc(BUF_SIZE);
	ft_bzero(tmp, BUF_SIZE);
	}
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		tmp2 = ft_memalloc(BUF_SIZE);
		ft_memcpy(tmp2, buf, BUF_SIZE);	
		tmp3 = ft_memalloc(ft_strlen(tmp));
		ft_memcpy(tmp3, tmp, ft_strlen(tmp));
		tmp = ft_memalloc(ft_strlen(tmp) + BUF_SIZE);
		ft_memcpy(tmp, tmp3, ft_strlen(tmp3));	
		ft_strncat(tmp, buf, BUF_SIZE);	
		ft_bzero(buf, BUF_SIZE);
	}
	printf("tmp est de : %s\n\n", tmp);
	ft_set_line(line, tmp);
	return (0);
}
