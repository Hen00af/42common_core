/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 15:41:26 by shattori          #+#    #+#             */
/*   Updated: 2024/11/06 18:09:53 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(const char *str, const char charset)
{
	int	count;
	int	i;
	int	in_words;

	in_words = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != charset && in_words == 0)
		{
			in_words = 1;
			count++;
		}
		else if (str[i] == charset)
			in_words = 0;
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

void	memory_error(char **result, int count)
{
	if (!result[count++])
	{
		while (--count >= 0)
			free(result[count]);
		free(result);
	}
}

void	split_words(char **result, const char *str, const char charset)
{
	int	start;
	int	i;
	int	count;

	start = -1;
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != charset && start == -1)
			start = i;
		else if ((str[i] == charset || str[i + 1] == '\0') && start != -1)
		{
			result[count] = ft_strndup(str + start, i - start
					+ (str[i] != charset));
			if (!result[count++])
			{
				memory_error(result, count);
			}
			start = -1;
		}
		i++;
	}
	result[count] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		cnt;
	char	**result;

	if (!s)
		return (NULL);
	cnt = word_count(s, c);
	result = (char **)malloc((cnt + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	split_words(result, s, c);
	if (result[cnt] != NULL)
		result[cnt] = NULL;
	return (result);
}
