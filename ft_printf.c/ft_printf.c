/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:20:12 by shattori          #+#    #+#             */
/*   Updated: 2024/11/22 04:03:09 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	deal_num(void);

int	deal_char(str);

int	handle_format(char *str)
{
	if (*(str + 1) == 'd')
		return (0);
	else if (*(str + 1) == 'c')
		return (1);
	else if (*(str + 1) == 's')
		return (2);
	else if (*(str + 1) == 'p')
		return (3);
	else if (*(str + 1) == 'i')
		return (4);
	else if (*(str + 1) == 'u')
		return (5);
	else if (*(str + 1) == 'x')
		return (6);
	else if (*(str + 1) == 'X')
		return (7);
	else if (*(str + 1) == '%')
		return (8);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, str);
	while (str[len])
	{
		if (str[len] == '%' && str[len + 1] != '\0')
		{
			handle_format(*(str + len));
		}
		len++;
	}
	scan_strings(str);
	return (len);
}

int	main(void)
{
	int	i;
	int	num;

	i = 2;
	num = ft_printf("abcd%d %d %d", 10, 20, 30);
	printf("%d", num);
	return (0);
}

// void	func(char *arg_1, ...)
// {
// 	va_list	ap;

// 	va_start(ap, arg_1);
// 	printf("arg_2: %s\n", arg_1);
// 	printf("arg_3: %d\n", va_arg(ap, int));
// }

// int	main(void)
// {
// 	char	*arg_1;
// 	int		arg_2;
// 	double	arg_3;

// 	arg_1 = "aaaa";
// 	arg_2 = 5;
// 	arg_3 = 3.14;
// 	func(arg_1);
// 	return (0);
// }
