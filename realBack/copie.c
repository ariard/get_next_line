/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 12:20:16 by ariard            #+#    #+#             */
/*   Updated: 2016/11/25 18:53:54 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*tmp;

	if (!s1 || !s2)
		return (NULL);
	new = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) +
				ft_strlen(s2)) + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (*s1)
	{
		*new = *s1;
		new++;
		s1++;
	}
	while (*s2)
	{
		*new = *s2;
		new++;
		s2++;
	}
	*new = '\0';
	return (tmp);
}
