/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 20:53:59 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:38:01 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @brief Implementation of the ft_putnbr_fd function.
 */

#include "libft.h"

/**
 * @brief Writes an integer to the specified file descriptor.
 *
 * This function writes the integer 'n' to the file descriptor 'fd'.
 *
 * @param n  The integer to be written.
 * @param fd The file descriptor to which the integer is written.
 */
void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];
	int		i;
	int		digit;

	i = 11;
	s[--i] = '\0';
	if (n == 0)
		s[--i] = '0';
	else if (n < 0)
	{
		write(fd, "-", 1);
		digit = -(n % 10);
		s[--i] = (char)digit + '0';
		n = -(n / 10);
	}
	while (n > 0)
	{
		digit = n % 10;
		s[--i] = (char)digit + '0';
		n = n / 10;
	}
	ft_putstr_fd(&s[i], fd);
}
