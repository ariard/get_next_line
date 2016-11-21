/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 21:10:58 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 13:27:40 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char		*ft_set_line(char **line, char *s)
{
	char 	*new_tmp;
	char	*keep;

	keep = ft_memalloc(ft_strlen(s));
	new_tmp = ft_memalloc(ft_strlen(s));
	keep = new_tmp;
	while (*s != 10 && *s != '\0')
	{
		*new_tmp = *s;
		new_tmp++;
		s++;
	}
	s++;
	*new_tmp = '\0';
	*line = keep;
	free(keep);
	return (s);
//	printf("%s", *line);
}

int			get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUF_SIZE];
	size_t 		len;
	static char	*tmp;
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
		if (ret == -1)
			return (-1);
		else if (ret == 0)
			return (0);
		len = ft_strlen(tmp);
		tmp3 = ft_memalloc(len);
		ft_memmove(tmp3, tmp, len);
//		printf("tmp est de : %s\n", tmp);	
		tmp = ft_memalloc(len + BUF_SIZE);
//		printf("now tmp est de : %s\n", tmp);
		ft_memmove(tmp, tmp3, ft_strlen(tmp3));	
		free(tmp3);
		ft_strncat(tmp, buf, BUF_SIZE);
		ft_bzero(buf, BUF_SIZE);
	}
//	printf("tmp est de : %s\n\n", tmp);
	tmp = ft_set_line(line, tmp);
	return (1);
}
