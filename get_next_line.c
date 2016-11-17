/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:32:50 by ariard            #+#    #+#             */
/*   Updated: 2016/11/17 22:01:41 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_strlen_chr(char *s, char c)
{
	int				i;
	
	i = 0;
	while (*s++ != c)
		i++;
	return (i);
}

int					get_next_line(const int fd, char **line)
{
	static char		buf[BUF_SIZE];
	char			*tmp;
	char			*tmp2;
	int				ret;


	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	tmp = buf;
	(void)line;
	if (!(tmp2 = (char *)malloc(sizeof(char) * ft_strlen_chr(tmp, 10))))
		return (0);
	while (*tmp != 10)
	{
		*tmp2 = *tmp;
		tmp++;
		tmp2++;
	}
	tmp++;
	ft_putstr(tmp2);
//	ft_putstr(tmp);	
	ft_memmove(buf, tmp, BUF_SIZE);
	return (ret);
}

//UTILISER UN AUTRE POINTEUR, Y COPIER TMP ET LE COPIER DANS LINE
//copier buf dans line
// -calculer longeur a mallocer -verifier la copie 1 par 1
//retenir buffer
//gerer erreur
//sauter '\n'
//verifier les entrees
//leaks memoires
//gerer les comportements indifferents
//comment detecter fin du fichier
