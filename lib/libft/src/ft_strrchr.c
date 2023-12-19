/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 16:49:00 by vde-frei          #+#    #+#             */
/*   Updated: 2023/07/27 11:32:06 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				index;
	unsigned char	*string;

	string = (unsigned char *)s;
	index = ft_strlen(s);
	while (index)
	{
		if (string[index] == (unsigned char)c)
			return ((char *)(string + index));
		--index;
	}
	if (string[index] == (unsigned char)c)
		return ((char *)(string + index));
	return (NULL);
}
