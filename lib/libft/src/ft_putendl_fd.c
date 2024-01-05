/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:40:56 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:37:08 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putendl_fd.c
 * @brief Implementation of the ft_putendl_fd function.
 */

#include "libft.h"

/**
 * @brief Writes a string followed by a newline character to the specified
 * file descriptor.
 *
 * This function writes the string 's' followed by a newline character to the
 * file descriptor 'fd'. It utilizes the ft_putstr_fd function for writing the
 * string.
 *
 * @param s  The string to be written.
 * @param fd The file descriptor to which the string and newline character are
 *        written.
 */
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
