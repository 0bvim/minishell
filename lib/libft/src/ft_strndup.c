/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:48:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/05 13:13:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strndup.c
 * @brief Implementation of the ft_strndup function.
 */

#include "libft.h"

/**
 * @brief Creates a duplicate of a string up to a specified length.
 *
 * This function creates a new string that is a duplicate of the input
 * string `s`, up to a maximum length of `n` characters. If the length of `s`
 * is less than `n`,
 * the entire string is duplicated. The resulting string is null-terminated.
 *
 * @param s The input string to be duplicated.
 * @param n The maximum number of characters to be duplicated.
 * @return A pointer to the newly allocated duplicated string, or NULL if
 * the allocation fails.
 */
char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (n < i)
		i = n;
	ptr = malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s && *s && i < n)
		ptr[i++] = *s++;
	ptr[i] = '\0';
	return (ptr);
}
