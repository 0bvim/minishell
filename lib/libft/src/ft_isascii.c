/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:39:41 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:19:13 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isascii.c
 * @brief Implementation of the ft_isascii function.
 */

/**
 * @brief Checks if the given character is a valid ASCII character.
 *
 * This function checks if the given character is a valid ASCII character,
 * i.e., its ASCII value lies in the range [0, 127].
 *
 * @param c The character to be checked.
 * @return 1 if the character is a valid ASCII character, 0 otherwise.
 */
int	ft_isascii(int c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}
