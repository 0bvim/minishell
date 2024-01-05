/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:35:18 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:43:01 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @brief Implementation of the ft_strchr function.
 */

#include <stddef.h>

/**
 * @brief Locates the first occurrence of a character in a string.
 *
 * This function searches for the first occurrence of the character 'c' in the
 * string 's'. The null-terminating character ('\0') is considered part of the
 * string.
 *
 * @param s A pointer to the null-terminated string to be searched.
 * @param c The character to be located.
 * @return A pointer to the first occurrence of the character 'c' in the
 *         string 's', or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c)
{
	while (*s)
		if (*s++ == (unsigned char)c)
			return ((char *)--s);
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
