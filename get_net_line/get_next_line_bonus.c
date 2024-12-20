/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:52:47 by shattori          #+#    #+#             */
/*   Updated: 2024/11/20 13:26:41 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	t_str	ret;
	char	c;

	ret.str = NULL;
	ret.len = 0;
	ret.capa = 0;
	while (1)
	{
		c = ft_getchar(fd);
		if (c == EOF)
			break ;
		ft_putchar(&ret, c);
		if (c == '\n')
			break ;
	}
	if (c == EOF && ret.len == 0)
		return (NULL);
	if (ret.len > 0)
		ft_putchar(&ret, '\0');
	return (ret.str);
}
