/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:44:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/04 14:17:07 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	alloc_mem(char **split_array, char const *s, char c)
{
	int	index;
	int	letters;

	index = 0;
	letters = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
			{
				letters++;
				s++;
			}
			split_array[index] = ft_calloc((letters + 1), sizeof(char));
			index++;
			letters = 0;
		}
		else
			s++;
	}
}

static int	count_word(const char *s, char c)
{
	int	index;
	int	words;

	index = 0;
	words = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c)
		{
			words++;
			while (s[index] != c && s[index] != '\0')
				index++;
		}
		else
			index++;
	}
	return (words);
}

static void	fill_array(char **result_array, const char *s, char c)
{
	int	word;
	int	letters;

	word = 0;
	letters = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != c && *s != '\0')
			{
				result_array[word][letters] = *s;
				s++;
				letters++;
			}
			word++;
			letters = 0;
		}
		else
			s++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;

	words = count_word(s, c);
	result = ft_calloc((words + 1), sizeof(char *));
	if (!s || !result)
		return (NULL);
	alloc_mem(result, s, c);
	fill_array(result, s, c);
	return (result);
}
