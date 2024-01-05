/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:44:21 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 11:01:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 * @brief Implementation of the ft_strrchr function.
 */

#include <stddef.h>

/**
 * @brief Locates the last occurrence of a character in a null-terminated
 * string.
 *
 * This function locates the last occurrence of the character 'c' (converted
 * to an unsigned char) in the null-terminated string 's'.
 *
 * @param s The null-terminated string to search in.
 * @param c The character to search for.
 * @return A pointer to the last occurrence of 'c' in 's', or NULL if 'c' is
 *         not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = NULL;
	while (*s)
	{
		if (*s++ == (unsigned char)c)
			occ = (char *)(s - 1);
	}
	if (!(unsigned char)c)
		occ = (char *)(s);
	return (occ);
}
