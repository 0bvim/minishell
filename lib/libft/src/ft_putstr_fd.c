/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:34:31 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:39:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putstr_fd.c
 * @brief Implementation of the ft_putstr_fd function.
 */

#include <unistd.h>

/**
 * @brief Writes a string to the specified file descriptor.
 *
 * This function writes the string 's' to the file descriptor 'fd'.
 *
 * @param s  The string to be written.
 * @param fd The file descriptor to which the string is written.
 */
void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
	write(fd, s, i);
}
