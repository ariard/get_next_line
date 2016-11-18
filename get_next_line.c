/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:32:50 by ariard            #+#    #+#             */
/*   Updated: 2016/11/18 15:48:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_strlenchr(char *s, char c)
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
	char			*tmp3;
	int				ret;
	int				len;
	int				i;

	ret = read(fd, buf, BUF_SIZE);
	if (ret > 0)
		buf[ret] = '\0';
	tmp = buf;
	if (!(tmp2 = (char *)malloc(sizeof(char) * ft_strlenchr(tmp, 10))))
		return (0);
	len = ft_strlen(buf);
	i = 0;
	if (!(tmp3 = (char *)malloc(sizeof(char) * ft_strlenchr(tmp, 10))))
		return (0);
	tmp3 = tmp2;
	while (*tmp != 10 && i < len)
	{
		*tmp2 = *tmp;
		tmp++;
		i++;
		tmp2++;
	}
	*tmp2 = '\0';
	tmp++;	
	*line = tmp3;
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
