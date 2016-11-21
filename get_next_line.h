/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:33:07 by ariard            #+#    #+#             */
/*   Updated: 2016/11/21 22:10:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define BUFF_SIZE 10

void	*ft_memalloc(size_t size);

char	*ft_strncat(char *s1, const char *s2, size_t n);

int		get_next_line(const int fd, char **line);

size_t	ft_strlen(char *s);

#endif
