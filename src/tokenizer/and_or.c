/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:23 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/05 13:55:04 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenize_and(char **p, t_token **tokens, int *num)
{
	if (**p == '&' && *(*p + 1) == '&')
	{
		(*tokens)[*num].type = TOKEN_AND;
		(*tokens)[*num].value = "&&";
		(*num)++;
		*p += 2;
	}
}

void tokenize_or(char **p, t_token **tokens, int *num)
{
	if (**p == '|' && *(*p + 1) == '|' && *(*p + 2) != '|')
	{
		(*tokens)[*num].type = TOKEN_OR;
		(*tokens)[*num].value = "||";
		(*num)++;
		*p += 2;
	}
	else if ((**p == '|' && *(*p + 1) != '|') || (*(*p + 2) == '|'))
	{
		(*p)++;
		ft_putstr_fd("Sintax error\n", STDERR_FILENO);
	}
}
