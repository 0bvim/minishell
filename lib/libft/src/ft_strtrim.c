/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:58:22 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 11:03:37 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtrim.c
 * @brief Implementation of the ft_strtrim function.
 */

#include <stdlib.h>

static int	ft_is_in(const char c, char const *set)
{
	while (*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

static char	*ft_while_in_set(char const *ptr_init, char const *set, int dir)
{
	char	*ptr;

	ptr = (char *)ptr_init;
	if (dir == -1 && *ptr)
	{
		while (*ptr)
			ptr++;
		ptr--;
	}
	while (ptr >= (char *)ptr_init && ft_is_in(*ptr, set))
		ptr += dir;
	if (ptr < (char *)ptr_init)
		return ((char *)ptr_init);
	return (ptr);
}

/**
 * @brief Allocates and trims a copy of the input string by removing specified
 *        characters from the beginning and end.
 *
 * This function allocates and returns a new string that is a trimmed version
 * of the input string 's1'.
 * Trimming involves removing characters from the beginning and end of the
 * string that are present in the set 'set'.
 *
 * @param s1  The input string to trim.
 * @param set The set of characters to remove from the beginning and end of the
 *        string.
 * @return A newly allocated trimmed string, or NULL if memory allocation
 *         fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	char			*start;
	char			*end;
	char			*str;
	unsigned int	i;

	if (!s1 || !set)
		return (NULL);
	start = ft_while_in_set(s1, set, 1);
	end = ft_while_in_set(start, set, -1);
	if (end == start && !*start)
		str = malloc(1);
	else
		str = malloc((size_t)(end - start) + 2);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = *(start++);
	str[i] = '\0';
	return (str);
}
