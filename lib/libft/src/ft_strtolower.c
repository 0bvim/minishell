/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:23:49 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/19 14:44:50 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtolower.c
 * @brief Implementation of the ft_strtolower function.
 */

#include "libft.h"

/**
 * @brief Converts all characters in a string to lowercase.
 *
 * This function iterates through each character in the input string
 * and converts it to lowercase using the ft_tolower function.
 *
 * @param str The input string to be converted to lowercase.
 * @return    A pointer to the beginning of the modified string.
 */
char	*ft_strtolower(char	*str)
{
	char	*begin;

	begin = str;
	while (*str)
	{
		*str = ft_tolower((int)*str);
		str++;
	}
	return (begin);
}
