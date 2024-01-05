/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:01:23 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/30 16:57:39 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isspace.c
 * @brief Implementation of the ft_isspace function.
 */

/**
 * @brief Check if the given character is a white space character.
 *
 * This function checks whether the input character is a white space
 * character, including space (' '), tab ('\t'), newline ('\n'), vertical
 * tab ('\v'),form feed ('\f'), and carriage return ('\r').
 *
 * @param c The character to check.
 * @return Returns 1 if the character is a white space character, and 0
 * otherwise.
 */
int	ft_isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
