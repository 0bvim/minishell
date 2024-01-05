/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:18:33 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:35:31 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memset.c
 * @brief Implementation of the ft_memset function.
 */

#include <stddef.h>

/**
 * @brief Fills a memory block with a specified byte value.
 *
 * This function fills the first 'n' bytes of the memory block pointed to
 * by 's' with the specified byte 'c'.
 *
 * @param s A pointer to the memory block to be filled.
 * @param c The byte value to be set.
 * @param n The number of bytes to fill.
 * @return A pointer to the memory block 's'.
 */
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned long	i;

	i = -1;
	while (++i < n)
		((unsigned char *)s)[i] = (unsigned char)c;
	return (s);
}
