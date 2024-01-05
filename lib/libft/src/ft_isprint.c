/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:52:35 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:19:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 * @brief Implementation of the ft_isprint function.
 */

/**
 * @brief Checks if the given character is a printable character.
 *
 * This function checks if the given character is a printable character,
 * i.e., its ASCII value is in the range of printable characters [32, 126].
 *
 * @param c The character to be checked.
 * @return 1 if the character is printable, 0 otherwise.
 */
int	ft_isprint(int c)
{
	if (' ' <= c && c <= '~')
		return (1);
	return (0);
}
