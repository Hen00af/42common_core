/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:51:45 by shattori          #+#    #+#             */
/*   Updated: 2024/11/06 18:08:13 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *string1, const char *string2, size_t count)
{
	size_t	s;

	s = 0;
	if (count == 0)
	{
		return (0);
	}
	while (s < count)
	{
		if (string1[s] == '\0' || string2[s] == '\0')
		{
			return ((int)(string1[s] - string2[s]));
		}
		if ((int)(string1[s] != string2[s]))
		{
			return ((int)(string1[s] - string2[s]));
		}
		s++;
	}
	return (0);
}
