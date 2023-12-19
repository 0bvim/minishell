/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:36:40 by vde-frei          #+#    #+#             */
/*   Updated: 2023/07/24 19:46:59 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	if (n != 0)
	{
		while (s1[index] && (s1[index] == s2[index]) && index < n - 1)
			index++;
		return ((unsigned char)s1[index] - (unsigned char)s2[index]);
	}
	return (0);
}
