/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:32:50 by ariard            #+#    #+#             */
/*   Updated: 2016/11/18 15:03:49 by ariard           ###   ########.fr       */
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
	int				len2;
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
	if (!(line = (char **)malloc(sizeof(char *) * ft_strlenchr(tmp, 10))))
		return (0);
	while (*tmp != 10 && i < len)
	{
		*tmp2 = *tmp;
		tmp++;
		i++;
		tmp2++;
	}
	*tmp2 = '\0';
	tmp++;	
	if (!(line = (char **)malloc(sizeof(char *) * ft_strlen(tmp3) + 1)))
		return (0);
//	ft_putnbr(ft_strlen(tmp3));
	len2 = ft_strlen(tmp3);
	while (len2--)
	{
		*line = tmp3;
		ft_putchar(**line);
		line++;
		tmp3++;
	}
//	ft_putstr(tmp3);
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
