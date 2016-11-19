/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 21:10:58 by ariard            #+#    #+#             */
/*   Updated: 2016/11/19 21:55:01 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE];
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	while (ret = read(fd, buf, BUF_SIZE) == 0)
	{
	
