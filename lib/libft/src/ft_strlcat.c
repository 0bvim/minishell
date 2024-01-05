/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:09:14 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:51:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcat.c
 * @brief Implementation of the ft_strlcat function.
 */

#include "libft.h"

static size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	i;

	i = 0;
	while (s[i] && i < maxlen)
		i++;
	return (i);
}

/**
 * @brief Appends a string to another, ensuring null-termination.
 *
 * This function appends the null-terminated string 'src' to the end of the
 * null-terminated string 'dst', ensuring that the total length of the
 * resulting string does not exceed 'size' characters, including the
 * null-terminator.
 *
 * @param dst  The destination null-terminated string.
 * @param src  The source null-terminated string to be appended.
 * @param size The size of the destination buffer, including the
 *        null-terminator.
 * @return The total length of the concatenated string (not including the
 *         null-terminator).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size)
		len = ft_strnlen(dst, size);
	if (len == size)
		return (len + ft_strlen(src));
	return (len + ft_strlcpy(dst + len, src, size - len));
}
