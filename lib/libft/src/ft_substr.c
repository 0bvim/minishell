/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:56:48 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/30 01:48:12 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux_sub;
	size_t	aux_len;

	aux_len = ft_strlen(s);
	if (start > aux_len)
		return (ft_strndup("", 0));
	if (aux_len >= len)
		aux_len = len;
	if (ft_strlen(s) - start < aux_len)
		aux_len = ft_strlen(&s[start]);
	aux_sub = (char *)ft_calloc(aux_len + 1, sizeof(char));
	if (aux_sub)
		ft_strlcpy(aux_sub, &s[start], aux_len + 1);
	return (aux_sub);
}
