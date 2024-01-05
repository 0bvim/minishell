/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:30:09 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 11:07:13 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_toupper.c
 * @brief Implementation of the ft_toupper function.
 */

/**
 * @brief Converts a lowercase letter to its corresponding uppercase letter.
 *
 * This function takes an integer representing an ASCII character and, if the
 * character is a lowercase letter ('a' to 'z'), converts it to its
 * corresponding uppercase letter. If the input character is not a lowercase
 * letter, it is returned unchanged.
 *
 * @param c The integer representing the ASCII character to convert.
 * @return The uppercase equivalent of the input character, or the input
 *         character itself if it is not a lowercase letter.
 */
int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}
