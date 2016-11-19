/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:33:07 by ariard            #+#    #+#             */
/*   Updated: 2016/11/19 21:55:07 by ariard           ###   ########.fr       */
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

void	ft_putchar(char c);

void	ft_putstr(char *s);

void	*ft_memmove(void *dest, const void *src, size_t size);

void	*ft_memcpy(void *dest, const void *src, size_t size);

int		get_next_line(const int fd, char **line);

void	ft_putnbr(int n);

size_t	ft_strlen(char *s);

#endif
