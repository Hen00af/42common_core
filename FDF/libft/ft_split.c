/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:41:26 by shattori          #+#    #+#             */
/*   Updated: 2024/11/13 21:10:35 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *s, char c)
{
	int	count;
	int	i;
	int	in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
		{
			in_word = 0;
		}
		i++;
	}
	return (count);
}

char	*ft_strndup(const char *src, int n)
{
	char	*dest;
	int		i;

	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_result(char **result, int count)
{
	while (--count >= 0)
		free(result[count]);
	free(result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		start;
	int		count;
	char	**result;

	if (!s)
		return (NULL);
	count = word_count(s, c);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	start = -1;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if ((s[i] == c || s[i + 1] == '\0') && start != -1)
		{
			result[count] = ft_strndup(s + start, i - start + (s[i] != c));
			if (!result[count])
			{
				free_result(result, count);
				return (NULL);
			}
			count++;
			start = -1;
		}
		i++;
	}
	result[count] = NULL;
	return (result);
}
