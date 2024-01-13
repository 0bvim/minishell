/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:56:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 21:11:30 by bmoretti         ###   ########.fr       */
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
	while (**str && ft_isspace(**str))
		(*str)++;
}
