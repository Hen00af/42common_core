/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 02:51:47 by shattori          #+#    #+#             */
/*   Updated: 2024/11/11 05:54:17 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src || !dst)
		return (NULL);
	while (i < n)
	{
		*((char *)dst + i) = *((char *)src + i);
		i++;
	}
	return (dst);
}

int	ft_getchar(int fd)
{
	static t_buff	buf;

	if (buf.n == 0)
	{
		buf.n = read(fd, buf.buf, sizeof(buf));
		buf.bufp = buf.buf;
	}
	return ((buf.n-- >= 0) ? (unsigned char)*buf.bufp++ : EOF);
}

char	*ft_putchar(t_str *str, char c)
{
	char	*new_str;

	if (str->len + 1 > str->capa)
	{
		str->capa *= 2;
		new_str = malloc(str->capa * sizeof(char));
		if (new_str == NULL)
			return (NULL);
		ft_memcpy(new_str, str->str, str->len);
		free(str->str);
		str->str = new_str;
	}
	str->str[str->len] = c;
	str->len++;
	str->str[str->len] = '\0';
	return (0);
}
