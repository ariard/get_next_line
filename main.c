/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:59:24 by ariard            #+#    #+#             */
/*   Updated: 2016/11/20 00:31:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int				fd;
	char 			**line;
	char			*a;

	(void)argc;
	a = "test";
	line = &a;
	printf("a est de : %s\n", a);
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);
//	printf("a est de : %s\n", a);
	get_next_line(fd, line);
//	printf("a est de : %s\n", a);
	get_next_line(fd, line);
//	printf("a est de : %s\n", a);
	get_next_line(fd, line);
//	printf("a est de : %s\n", a);
	return (0);
}
