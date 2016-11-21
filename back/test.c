/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:58:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/17 19:19:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		ft_read(const int fd, char **line)
{
	char		buf[1000];
	int			ret;


	(void)line;
//	while (read(fd, &buf, 1))	
//		ft_putchar(buf);
	ret = read(fd, buf, 10);
	while (ret && fd != -1)
	{
		buf[ret] = 0;
		ft_putstr(buf);
		ret = read(fd, buf, 10);
		ft_putchar('\n');
	}
//	ret = read(fd, buf, 1000 + 1);
//	buf[ret] = 0;
//	ft_putstr(buf);
	return (0);
}
