/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:46:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:17:29 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_bzero.c
 * @brief Implementation of the ft_bzero function.
 */

#include <stddef.h>

/**
 * @brief Sets the first n bytes of the memory area pointed to by s to zero.
 *
 * This function sets the first n bytes of the memory area pointed to by s
 * to zero (interpreted as an unsigned char).
 *
 * @param s A pointer to the memory area.
 * @param n The number of bytes to set to zero.
 */
void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	if (!n)
		return ;
	ptr = (char *)s;
	while (n-- != 0)
		*(ptr++) = '\0';
}
