/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 20:41:42 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:58:20 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strncmp.c
 * @brief Implementation of the ft_strncmp function.
 */

#include <stddef.h>

/**
 * @brief Compares two null-terminated strings up to a specified length.
 *
 * This function compares the null-terminated strings 's1' and 's2' up to a
 * specified length 'n'. The comparison is performed using the ASCII values
 * of the characters. The function returns an integer less than, equal to, or
 * greater than zero if 's1' is found, respectively, to be less than, to match,
 * or be greater than 's2'.
 *
 * @param s1 The first null-terminated string.
 * @param s2 The second null-terminated string.
 * @param n  The maximum number of characters to compare.
 * @return An integer less than, equal to, or greater than zero if 's1' is
 *         found, respectively, to be less than, to match, or be greater
 *         than 's2'.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while ((*s1 || *s2) && (n-- > 0))
	{
		if (*(s1++) != *(s2++))
			return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
	}
	return (0);
}
