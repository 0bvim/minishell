/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:26:54 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:53:53 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlen.c
 * @brief Implementation of the ft_strlen function.
 */

#include <stddef.h>

/**
 * @brief Calculates the length of a null-terminated string.
 *
 * This function calculates the length of the null-terminated string 's'.
 *
 * @param s The null-terminated string.
 * @return The length of the string (excluding the null-terminator).
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
