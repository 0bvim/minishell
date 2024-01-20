/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:49:00 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/20 09:32:49 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmerge.c
 * @brief Implementation of the ft_strmerge function.
 */

#include "libft.h"

/**
 * @brief Merges two strings into one. The two strings are freed.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The merged string.
 */
char	*ft_strmerge(char *s1, char *s2)
{
	char	*merged;

	merged = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (merged);
}
