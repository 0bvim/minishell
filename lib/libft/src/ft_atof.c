/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 16:13:31 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/30 16:43:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atof.c
 * @brief Implementation of the ft_atof function.
 */

#include "libft.h"

/**
 * @brief Convert a string to a double-precision floating-point number.
 *
 * This function converts the initial portion of the string pointed to by `nptr`
 * to a `double` representation. It skips leading white-space characters,
 * interprets an optional sign, and processes the integral and fractional parts.
 *
 * @param nptr A pointer to the string to convert.
 * @return The converted `double` value.
 */
double	ft_atof(const char *nptr)
{
	int		sign;
	double	nb;
	int		divider;

	sign = 1;
	nb = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' && ft_isdigit(*(nptr + 1)))
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr == '0')
		nptr++;
	while (ft_isdigit(*nptr))
		nb = nb * 10 + (*(nptr++) - '0');
	if (*nptr == '.')
		nptr++;
	divider = 10;
	while (ft_isdigit(*nptr))
	{
		nb += (double)(*(nptr++) - '0') / divider;
		divider *= 10;
	}
	return (sign * nb);
}
