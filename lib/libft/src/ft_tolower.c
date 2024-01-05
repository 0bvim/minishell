/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:33:28 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 11:06:11 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @brief Implementation of the ft_tolower function.
 */

/**
 * @brief Converts an uppercase letter to its corresponding lowercase letter.
 *
 * This function takes an integer representing an ASCII character and, if the
 * character is an uppercase letter ('A' to 'Z'), converts it to its
 * corresponding lowercase letter. If the input character is not an uppercase
 * letter, it is returned unchanged.
 *
 * @param c The integer representing the ASCII character to convert.
 * @return The lowercase equivalent of the input character, or the input
 *         character itself if it is not an uppercase letter.
 */
int	ft_tolower(int c)
{
	if ('A' <= c && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}
