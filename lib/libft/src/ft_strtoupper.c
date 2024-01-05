/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 14:23:49 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/19 14:45:39 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strtoupper.c
 * @brief Implementation of the ft_strtoupper function.
 */

#include "libft.h"

/**
 * @brief Converts all characters in a string to uppercase.
 *
 * This function iterates through each character in the input string
 * and converts it to uppercase using the ft_toupper function.
 *
 * @param str The input string to be converted to uppercase.
 * @return    A pointer to the beginning of the modified string.
 */
char	*ft_strtoupper(char	*str)
{
	char	*begin;

	begin = str;
	while (*str)
	{
		*str = ft_toupper((int)*str);
		str++;
	}
	return (begin);
}
