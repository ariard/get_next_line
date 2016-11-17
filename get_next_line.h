/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:33:07 by ariard            #+#    #+#             */
/*   Updated: 2016/11/17 22:01:47 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1000

void	ft_putchar(char c);

void	ft_putstr(char *s);

void	*ft_memmove(void *dest, const void *src, size_t size);

char	*ft_memcpy(void *dst, const void *src, size_t n);

int		ft_read(const int fd, char **line);

int		get_next_line(const int fd, char **line);

#endif
