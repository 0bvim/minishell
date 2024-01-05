/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:57:02 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/22 16:04:04 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_abs.c
 * @brief Implementation of the ft_abs function.
 */

/**
 * Returns the absolute value of an integer.
 *
 * @param nb The integer whose absolute value is to be returned.
 * @return The absolute value of the integer.
 */
int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
