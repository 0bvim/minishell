/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:02:18 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:52:50 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcpy.c
 * @brief Implementation of the ft_strlcpy function.
 */

#include "libft.h"

/**
 * @brief Copies a string into a destination buffer with a specified size.
 *
 * This function copies the null-terminated string 'src' into the destination
 * buffer 'dst' with a specified size 'size'. The function ensures
 * null-termination and returns the length of the source string.
 *
 * @param dst  The destination buffer where the string is copied.
 * @param src  The null-terminated source string to be copied.
 * @param size The size of the destination buffer.
 * @return The length of the source string (excluding the null-terminator).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size > 0)
	{
		while (*src && size-- > 1)
			*(dst++) = *(src++);
		*dst = '\0';
	}
	return (src_len);
}
