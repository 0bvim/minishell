/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:56:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/14 04:17:08 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_issymbol(char c)
{
	if (ft_strchr(SYMBOLS, c))
		return (1);
	return (0);
}

void	ft_skip_spaces(const char **str)
{
	if (*str)
		while (**str && ft_isspace(**str))
			(*str)++;
}
