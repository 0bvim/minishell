/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 09:01:30 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:18:56 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalpha.c
 * @brief Implementation of the ft_isalpha function.
 */

/**
 * @brief Checks if the given character is an alphabetic character.
 *
 * This function checks if the given character is an alphabetic character,
 * i.e., an uppercase or lowercase letter (A-Z or a-z).
 *
 * @param c The character to be checked.
 * @return 1 if the character is alphabetic, 0 otherwise.
 */
int	ft_isalpha(int c)
{
	if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'))
		return (1);
	return (0);
}
