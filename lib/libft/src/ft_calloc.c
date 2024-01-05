/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:43:09 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:18:04 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @brief Implementation of the ft_calloc function.
 */

#include "libft.h"

/**
 * @brief Allocates memory for an array of nmemb elements, each of size size.
 *
 * This function allocates memory for an array of nmemb elements, each of size
 * size, and initializes all bytes to zero.
 *
 * @param nmemb Number of elements in the array.
 * @param size  Size of each element in bytes.
 * @return A pointer to the allocated memory, or NULL if allocation fails.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total;

	total = nmemb * size;
	if (nmemb && total / nmemb != size)
		return (NULL);
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
