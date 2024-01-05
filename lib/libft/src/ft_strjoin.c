/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 08:20:17 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:49:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 * @brief Implementation of the ft_strjoin function.
 */

#include "libft.h"

/**
 * @brief Concatenates two strings into a newly allocated string.
 *
 * This function concatenates the strings 's1' and 's2' into a newly allocated
 * string, and returns a pointer to the newly created string. The caller is
 * responsible for freeing the allocated memory.
 *
 * @param s1 The first null-terminated string.
 * @param s2 The second null-terminated string.
 * @return A pointer to the newly allocated string containing the concatenated
 *         strings, or NULL in case of memory allocation failure or if either
 *         's1' or 's2' is NULL.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joined;
	char	*origin;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	joined = malloc(len + 1);
	if (joined == NULL)
		return (NULL);
	origin = joined;
	while (*s1)
		*(joined++) = *(s1++);
	while (*s2)
		*(joined++) = *(s2++);
	*joined = '\0';
	return (origin);
}
