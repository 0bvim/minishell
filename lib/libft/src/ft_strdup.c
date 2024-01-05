/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:42:46 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:49:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @brief Implementation of the ft_strdup function.
 */

#include <stdlib.h>

/**
 * @brief Duplicates a string by allocating memory for a new string.
 *
 * This function duplicates the null-terminated string 's' by allocating
 * memory for a new string and copying the characters from 's' to the newly
 * allocated memory.
 *
 * @param s A pointer to the null-terminated string to be duplicated.
 * @return A pointer to the newly allocated string, which is a duplicate of
 *         's'. Returns NULL in case of memory allocation failure.
 */
char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	while (s[i])
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	i = 0;
	while (s && *s)
		ptr[i++] = *s++;
	ptr[i] = '\0';
	return (ptr);
}
