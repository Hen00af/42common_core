/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:52:47 by shattori          #+#    #+#             */
/*   Updated: 2024/11/11 01:38:29 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int get_next_line(FILE *fd)
// {
//     static char buf[BUFSIZ];
//     static char* bufp;
//     static int n = 0;

//     if (n == 0)
//     {
//         n = fread(buf, 1, sizeof(buf), fd);
//         bufp = buf;
//     }
//     return ((n-- > 0) ? (unsigned char) *bufp++ : EOF);
// }

int	ft_getc(int fd)
{
	static char	save;
	int			n;

	n = read(fd, &save, 1);
	if (n <= 0)
		return (EOF);
	return (save);
}

int	main(void)
{
	int	fd;
	int	c;

	fd = open("text.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (1);
	}
	while ((c = ft_getc(fd)) != EOF && c != '\n')
		write(1, &c, 1);
	close(fd);
	return (0);
}
