/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 20:08:46 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 11:00:12 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @brief Implementation of the ft_strnstr function.
 */

#include <stddef.h>

/**
 * @brief Locates the first occurrence of a substring in a limited range.
 *
 * This function locates the first occurrence of the null-terminated
 * substring 'little' in the null-terminated string 'big', up to a specified
 * length 'len'.
 *
 * @param big    The null-terminated string to search in.
 * @param little The null-terminated substring to search for.
 * @param len    The maximum number of characters to search in the string
 *               'big'.
 * @return A pointer to the first occurrence of 'little' in 'big' within the
 *         specified range, or NULL if 'little' is not found or 'big' is NULL.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	if (!*little)
		return ((char *)big);
	if (!big && !len)
		return (NULL);
	while (big[i] && i < len)
	{
		j = 0;
		k = i;
		while (big[k] == little[j] && k < len)
		{
			k++;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
