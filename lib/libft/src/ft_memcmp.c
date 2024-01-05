/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 19:25:59 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:32:09 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcmp.c
 * @brief Implementation of the ft_memcmp function.
 */

#include <stddef.h>

/**
 * @brief Compares two memory blocks.
 *
 * This function compares the first 'n' bytes of the memory blocks pointed to
 * by 's1' and 's2'. It returns an integer less than, equal to, or greater than
 * zero if the first differing byte is less than, equal to, or greater than
 * the corresponding byte in 's2'.
 *
 * @param s1 A pointer to the first memory block.
 * @param s2 A pointer to the second memory block.
 * @param n  The number of bytes to compare.
 * @return An integer less than, equal to, or greater than zero.
 *         If the first differing byte is less than, equal to, or greater than
 *         the corresponding byte in 's2'.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*(ptr1++) != *(ptr2++))
			return (*(ptr1 - 1) - *(ptr2 - 1));
	}
	return (0);
}
