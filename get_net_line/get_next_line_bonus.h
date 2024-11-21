/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:22:36 by shattori          #+#    #+#             */
/*   Updated: 2024/11/22 02:19:00 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# if BUFFER_SIZE > INT_MAX
#  undef BUFFER_SIZE
#  define BUFFER_SIZE INT_MAX
# endif

typedef struct s_str
{
	char	*str;
	size_t	len;
	size_t	capa;
}			t_str;

typedef struct s_buff
{
	char	buf[BUFFER_SIZE];
	char	*bufp;
	int		n;
}			t_buff;

void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_getchar(int fd);
int			ft_putchar(t_str *str, char c);
char		*get_next_line(int fd);

#endif /* GET_NEXT_LINE_BONUS_H */
