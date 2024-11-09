/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:16:03 by shattori          #+#    #+#             */
/*   Updated: 2024/11/07 21:27:03 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, unsigned int count)
{
	char	*dptr;
	char	*sptr;
	int		cnt;

	if (!dst && !src)
		return (NULL);
	cnt = 0;
	if (dst > src)
	{
		dptr = (char *)dst + count - 1;
		sptr = (char *)src + count - 1;
		while (count--)
			*dptr-- = *sptr--;
	}
	else
	{
		dptr = (char *)dst;
		sptr = (char *)src;
		while (count--)
			*dptr++ = *sptr++;
	}
	return (dst);
}
