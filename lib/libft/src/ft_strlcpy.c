/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 11:07:26 by vde-frei          #+#    #+#             */
/*   Updated: 2023/07/27 19:17:14 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	if (!size)
		return (ft_strlen(src));
	i = -1;
	while (*(src + ++i) && --size)
	{
		*(dst + i) = *(src + i);
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}
