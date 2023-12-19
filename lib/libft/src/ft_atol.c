/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:18:58 by vde-frei          #+#    #+#             */
/*   Updated: 2023/11/15 10:57:48 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lint	ft_atol(const char *nptr)
{
	long int		nb;
	int				sign;
	char			*string;

	sign = 1;
	string = (char *)nptr;
	while ((*string >= 9 && *string <= 13) || *string == 32)
		string++;
	while (*string == '-' || *string == '+')
	{
		if (*(string + 1) == '-' || *(string + 1) == '+')
			return (0);
		if (*string == '-')
			sign = -1;
		string++;
	}
	nb = 0;
	while (*string >= '0' && *string <= '9')
	{
		nb *= 10;
		nb += *string - 48;
		string++;
	}
	return (nb *= sign);
}
