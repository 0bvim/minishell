/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:02:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/07/29 16:21:19 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ocurrence;
	size_t	lil_len;
	size_t	c;

	ocurrence = NULL;
	lil_len = ft_strlen(little);
	c = 0;
	while (big[c] && c < len && lil_len)
	{
		if (!ft_strncmp((big + c), little, lil_len) && (c + lil_len <= len))
		{
			ocurrence = (char *)(big + c);
			break ;
		}
		c++;
	}
	if (!lil_len)
		ocurrence = (char *)big;
	return (ocurrence);
}
