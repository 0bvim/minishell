/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:39:49 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/06 10:18:30 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @brief Implementation of the ft_memcpy function.
 */

#include <stddef.h>

/**
 * @brief Copies a specified number of bytes from one memory block to another.
 *
 * This function copies 'n' bytes from the memory block pointed to by 'src'
 * to the memory block pointed to by 'dest'. The memory blocks must not overlap.
 *
 * @param dest A pointer to the destination memory block.
 * @param src  A pointer to the source memory block.
 * @param n    The number of bytes to copy.
 * @return A pointer to the destination memory block.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_cpy;
	unsigned char	*src_cpy;

	if (!dest && !src)
		return (dest);
	dest_cpy = (unsigned char *)dest;
	src_cpy = (unsigned char *)src;
	while (n-- > 0)
		*(dest_cpy++) = *(src_cpy++);
	return (dest);
}
