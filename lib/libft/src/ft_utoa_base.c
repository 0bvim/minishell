/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 23:45:36 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/29 11:04:10 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_utoa_base.c
 * @brief Implementation of the ft_utoa_base function.
 */

#include "libft.h"

static size_t	ft_define_size(unsigned int n, int base)
{
	size_t	s;

	s = 1;
	if (n == 0)
		s++;
	while (n != 0)
	{
		n /= base;
		s++;
	}
	return (s);
}

static char	ft_digit_representation(int n)
{
	if (n <= 9)
		return ((char)n + '0');
	else
		return ((char)(n - 10) + 'a');
}

/**
 * @brief Converts an unsigned integer to a string representation in
 * a specified base.
 *
 * This function converts the given unsigned integer to its string
 * representation in the specified base. The base must be between
 * 2 and 36 (inclusive).
 *
 * @param n    The unsigned integer to be converted.
 * @param base The base for the conversion (between 2 and 36).
 * @return     A dynamically allocated string representing the unsigned
 * integer in the specified base.
 *             NULL is returned in case of an invalid base or memory
 * allocation failure.
 */
char	*ft_utoa_base(unsigned int n, int base)
{
	char	*a;
	size_t	size;

	if (base < 2 || base > 36)
		return (NULL);
	size = ft_define_size(n, base);
	a = ft_calloc(size, sizeof(char));
	if (a == NULL)
		return (NULL);
	size--;
	while (size--)
	{
		a[size] = ft_digit_representation(n % base);
		n /= base;
	}
	return (a);
}
