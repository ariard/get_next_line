/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:33:07 by ariard            #+#    #+#             */
/*   Updated: 2016/11/20 18:43:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 10

void	*ft_memalloc(size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t size);

void	ft_bzero(void *s, size_t n);

char	*ft_strncat(char *s1, const char *s2, size_t n);

void	ft_strdel(char **as);

int		get_next_line(const int fd, char **line);

size_t	ft_strlen(char *s);

#endif
