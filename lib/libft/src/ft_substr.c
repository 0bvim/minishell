/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:56:48 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/01 12:31:37 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux_sub;
	size_t	aux_len;

	aux_len = ft_strlen(s);
	if (start > aux_len)
		return (ft_strdup(""));
	if (aux_len >= len)
		aux_len = len;
	if (ft_strlen(s) - start < aux_len)
		aux_len = ft_strlen(&s[start]);
	aux_sub = (char *)ft_calloc(aux_len + 1, sizeof(char));
	if (aux_sub)
		ft_strlcpy(aux_sub, &s[start], aux_len + 1);
	return (aux_sub);
}
