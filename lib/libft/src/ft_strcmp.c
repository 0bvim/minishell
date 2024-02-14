/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:28:03 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/14 14:37:53 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strcmp.c
 * @brief Implementation of the ft_strcmp function.
 */

/**
 * @brief Compares two strings lexicographically.
 *
 * This function compares the strings pointed to by `s1` and `s2`.
 * The comparison is done lexicographically, character by character,
 * until a difference is found or the end of one of the strings is reached.
 *
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @return An integer greater than, equal to, or less than 0, depending on
 *         whether `s1` is greater than, equal to, or less than `s2`.
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*(s1++) != *(s2++))
			return (*(unsigned char *)(--s1) - *(unsigned char *)(--s2));
	}
	return (0);
}
