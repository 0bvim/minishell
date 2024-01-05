/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:24:51 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/30 16:12:14 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @brief Implementation of the ft_atoi function.
 */

#include "libft.h"

/**
 * @brief Converts a string to an integer.
 *
 * This function converts the initial portion of the string pointed to by nptr
 * to its equivalent integer representation.
 *
 * @param nptr A pointer to the string to be converted.
 * @return The converted integer value.
 */
int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (ft_isdigit(*nptr))
		nb = nb * 10 + (*(nptr++) - '0');
	return (sign * nb);
}
