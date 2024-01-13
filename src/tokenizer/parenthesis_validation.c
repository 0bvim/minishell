/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis_validation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:51:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 21:29:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_skip_quotes(const char **str)
{
	char	quote_type;

	if (**str == '\'' || **str == '"')
		quote_type = **str;
	else
		return (0);
	(*str)++;
	while (**str && **str != quote_type)
		(*str)++;
	if (**str)
		(*str)++;
	return (1);
}

int	parenthesis_validation(const char *str)
{
	int		left;
	int		right;

	left = 0;
	right = 0;
	while (*str)
	{
		if (*str == '(')
			left++;
		else if (*str == ')')
			right++;
		if (right > left)
			return (0);
		if (!ft_skip_quotes(&str))
			str++;
	}
	if (right == left)
		return (1);
	return (0);
}
