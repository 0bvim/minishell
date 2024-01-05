/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:20:44 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:41:32 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @brief Implementation of the ft_split function.
 */

#include "libft.h"

static unsigned int	ft_count_tokens(char const *s, char c)
{
	unsigned int	count;

	count = 1;
	if (!*s)
		return (0);
	while (*s == c)
		s++;
	while (*s)
	{
		if (*(s++) == c)
		{
			count++;
			while (*s == c)
				s++;
		}
	}
	if (*(s - 1) == c && count >= 1)
		count--;
	return (count);
}

static char	*ft_split_malloc(char *start, char c)
{
	unsigned int	i;
	char			*str;

	while (*start == c)
		start++;
	i = -1;
	while (start[++i])
	{
		if (start[i] == c)
		{
			str = malloc(i + 1);
			if (str == NULL)
				return (NULL);
			return (str);
		}
	}
	str = malloc(i + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

static char	*ft_copy_split(char *dest, char *src, char c)
{
	while (*src && *src == c)
		src++;
	while (*src && *src != c)
		*(dest++) = *(src++);
	*dest = '\0';
	if (*src)
		return (src + 1);
	return (src);
}

static char	**ft_clear(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free (tab[i++]);
	free (tab);
	return (NULL);
}

/**
 * @brief Splits a string into an array of tokens based on a specified
 *        delimiter.
 *
 * This function splits the string 's' into an array of tokens using the
 * delimiter 'c'.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return A dynamically allocated array of strings representing the tokens.
 *         Returns NULL in case of memory allocation failure or if 's' is
 *         NULL.
 */
char	**ft_split(char const *s, char c)
{
	char			**tab;
	char			*mover;
	unsigned int	i;
	unsigned int	n_tokens;

	if (!s)
		return (NULL);
	n_tokens = ft_count_tokens(s, c);
	tab = ft_calloc((size_t)n_tokens + 1, sizeof(char *));
	if (!tab)
		return (NULL);
	mover = (char *)s;
	i = -1;
	while (++i < n_tokens)
	{
		tab[i] = ft_split_malloc(mover, c);
		if (tab[i] == NULL)
			return (ft_clear(tab));
		mover = ft_copy_split(tab[i], mover, c);
	}
	return (tab);
}
