/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:08:19 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:34:53 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @brief Implementation of the ft_memmove function.
 */

#include <stddef.h>

/**
 * @brief Moves a specified number of bytes from one memory block to another.
 *
 * This function moves 'n' bytes from the memory block pointed to by 'src'
 * to the memory block pointed to by 'dest'. The memory blocks may overlap.
 *
 * @param dest A pointer to the destination memory block.
 * @param src  A pointer to the source memory block.
 * @param n    The number of bytes to move.
 * @return A pointer to the destination memory block.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*from;
	unsigned char	*to;

	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	if (to < from)
	{
		while (n-- > 0)
			*to++ = *from++;
	}
	else if (to > from)
	{
		while (n-- > 0)
			to[n] = from[n];
	}
	return (dest);
}
