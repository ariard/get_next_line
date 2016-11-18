/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 16:59:24 by ariard            #+#    #+#             */
/*   Updated: 2016/11/18 14:30:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int				fd;
	char 			**line;

	(void)argc;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, line);

	get_next_line(fd, line);

	get_next_line(fd, line);

	get_next_line(fd, line);

	return (0);
}
