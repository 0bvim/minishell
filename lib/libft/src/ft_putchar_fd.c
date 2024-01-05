/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:31:38 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:36:05 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putchar_fd.c
 * @brief Implementation of the ft_putchar_fd function.
 */

#include <unistd.h>

/**
 * @brief Writes a character to the specified file descriptor.
 *
 * This function writes the character 'c' to the file descriptor 'fd'.
 *
 * @param c  The character to be written.
 * @param fd The file descriptor to which the character is written.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
