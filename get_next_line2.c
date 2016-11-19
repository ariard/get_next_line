/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 21:10:58 by ariard            #+#    #+#             */
/*   Updated: 2016/11/19 23:32:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(const int fd, char **line)
{
	int		ret;
	size_t	len;
	char	buf[BUF_SIZE];
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	(void)line;
	ft_bzero(buf, BUF_SIZE);
	tmp = ft_memalloc(BUF_SIZE);
	ft_bzero(tmp, BUF_SIZE);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		tmp2 = ft_memalloc(BUF_SIZE);
		ft_memcpy(tmp2, buf, BUF_SIZE);	
		len= ft_strlen(tmp);
		tmp3 = ft_memalloc(len);
		ft_memcpy(tmp3, tmp, len);
		tmp = ft_memalloc(len + BUF_SIZE);
		ft_memcpy(tmp, tmp3, len);	
		ft_strncat(tmp, buf, BUF_SIZE);
		printf("tmp est de : %s\n", tmp);
		ft_bzero(buf, BUF_SIZE);
	}
	return (0);
}
