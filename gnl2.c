/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 13:11:13 by ariard            #+#    #+#             */
/*   Updated: 2016/11/18 14:06:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	char			buf[BUF_SIZE];

	int				ret;

	(void)line;
	ft_putnbr(fd);	
	ret = read(fd, buf, BUF_SIZE);
	ft_putnbr(ret);
	ft_putchar(10);
	ft_putstr(buf);
	return (0);
}
