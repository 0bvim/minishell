/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:54:07 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:16:17 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_itoa.c
 * @brief Implementation of the ft_itoa function.
 */

#include <stdlib.h>

static size_t	ft_define_size(int n)
{
	size_t	s;

	s = 1;
	if (n <= 0)
		s++;
	while (n != 0)
	{
		n /= 10;
		s++;
	}
	return (s);
}

/**
 * @brief Converts an integer to a string.
 *
 * This function converts the given integer to a string representation.
 *
 * @param n The integer to be converted.
 * @return A dynamically allocated string representing the integer.
 *         Returns NULL if memory allocation fails.
 */
char	*ft_itoa(int n)
{
	char		*a;
	size_t		size;
	short int	negative;

	size = ft_define_size(n);
	a = malloc(size);
	if (a == NULL)
		return (NULL);
	a[--size] = '\0';
	negative = 0;
	if (n < 0)
		negative = 1;
	if (n < 0)
		a[0] = '-';
	while (size)
	{
		if (n < 0)
			a[--size] = (-(n % 10)) + '0';
		else
			a[--size] = (n % 10) + '0';
		n /= 10;
	}
	if (negative)
		a[0] = '-';
	return (a);
}
