/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:27:52 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 20:36:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	count_quotes(const char *str,
	int *single_quotes, int *double_quotes)
{
	char	quote_type;

	*single_quotes = 0;
	*double_quotes = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			quote_type = *str;
			if (quote_type == '\'')
				(*single_quotes)++;
			else
				(*double_quotes)++;
			str++;
			while (*str && *str != quote_type)
				str++;
			if (*str == quote_type && *str == '\'')
				(*single_quotes)++;
			else if (*str == quote_type && *str == '"')
				(*double_quotes)++;
		}
		str++;
	}
}

int	quotes_validation(const char *str)
{
	int		single_quotes;
	int		double_quotes;

	count_quotes(str, &single_quotes, &double_quotes);
	if (single_quotes % 2 || double_quotes % 2)
		return (0);
	return (1);
}
