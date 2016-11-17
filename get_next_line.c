/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:32:50 by ariard            #+#    #+#             */
/*   Updated: 2016/11/17 20:26:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					get_next_line(const int fd, char **line)
{
	static char		buf[BUF_SIZE];
	char			*tmp;
	int				ret;

	ret = read(fd, buf, BUF_SIZE);
	tmp = buf;
	if (!(line = (char **)malloc(sizeof(char *) * 1000)))
		return (0);
	while (*tmp != 10)
	{
		line = &tmp;
		ft_putchar(**line);
		tmp++;
		line++;
	}	
	tmp++;
	ft_memmove(buf, tmp, BUF_SIZE);
//	ft_putstr(buf);
	return (ret);
}


//copier buf dans line
// -calculer longeur a mallocer -verifier la copie 1 par 1
//retenir buffer
//gerer erreur
//sauter '\n'
//verifier les entrees
//leaks memoires
//gerer les comportements indifferents
