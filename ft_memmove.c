/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:16:03 by shattori          #+#    #+#             */
/*   Updated: 2024/11/06 18:02:55 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, unsigned int count)
{
	char	*dptr;
	char	*sptr;
	int		cnt;

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
