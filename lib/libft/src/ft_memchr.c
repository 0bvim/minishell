/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:09:20 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:31:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 * @brief Implementation of the ft_memchr function.
 */

#include <stddef.h>

/**
 * @brief Locates the first occurrence of a byte in a memory block.
 *
 * This function searches for the first occurrence of the byte 'c' in the
 * first 'n' bytes of the memory block pointed to by 's'.
 *
 * @param s A pointer to the memory block to be searched.
 * @param c The byte to be located.
 * @param n The number of bytes to search.
 * @return A pointer to the first occurrence of the byte, or NULL if not found.
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return (ptr);
		ptr++;
	}
	return (NULL);
}
