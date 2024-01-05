/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 22:24:11 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 11:05:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_substr.c
 * @brief Implementation of the ft_substr function.
 */

#include "libft.h"

/**
 * @brief Allocates and returns a substring of the input string.
 *
 * This function allocates and returns a new string that is a substring of the
 * input string 's'. The substring starts at the index 'start' and has a
 * maximum length of 'len'. If 'start' is beyond the length of 's', an empty
 * string is returned.
 * If the sum of 'start' and 'len' exceeds the length of 's', the substring is
 * truncated.
 *
 * @param s     The input string from which to create a substring.
 * @param start The starting index of the substring.
 * @param len   The maximum length of the substring.
 * @return A newly allocated substring, or NULL if memory allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	size_t			i;
	unsigned int	len_s;

	if (!s)
		return (NULL);
	len_s = (unsigned int)ft_strlen(s);
	if (start >= len_s)
		len = 0;
	else if ((size_t)start + len > (size_t)len_s)
		len = (size_t)len_s - (size_t)start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start <= len_s && i < len)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
