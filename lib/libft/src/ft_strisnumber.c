/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:54:12 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/30 11:35:35 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strisnumber.c
 * @brief Implentation of the ft_strisnumber function
 */

/**
 * @brief Checks if a string is a number.
 *
 * @param str The string to check.
 * @return 1 if the string is a number, 0 otherwise.
 */
int	ft_strisnumber(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
		if (!('0' <= *str && *str <= '9') || *str != '.')
			return (0);
	return (1);
}
