/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:24:51 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/29 10:26:19 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoll.c
 * @brief Implementation of the ft_atoll function.
 */

#include "libft.h"

/**
 * @brief Converts a string to a long long integer.
 *
 * This function converts the initial portion of the string pointed to by nptr
 * to its equivalent long long integer representation.
 *
 * @param nptr A pointer to the string to be converted.
 * @return The converted long long integer value.
 */
long long	ft_atoll(const char *nptr)
{
	int				sign;
	long long		nb;

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
