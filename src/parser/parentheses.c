/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parentheses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:08 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/31 01:26:49 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenize_parentheses(char **p, t_token **tokens, int *num)
{
	if (**p == '(')
	{
		(*tokens)[*num].type = TOKEN_LPAREN;
		(*tokens)[*num].value = "(";
		(*num)++;
		(*p)++;
	}
	else if (**p == ')')
	{
		(*tokens)[*num].type = TOKEN_RPAREN;
		(*tokens)[*num].value = ")";
		(*num)++;
		(*p)++;
	}
}

void tokenize_quote(char **p, t_token **tokens, int *num)
{
	char quote;
	char *begin;
	int quote_count;

	if (**p == '"' || **p == '\'')
	{
		quote = **p;
		begin = ++(*p);
		quote_count = 1;
		while (**p && quote_count > 0)
		{
			if (**p == quote)
				quote_count++;
			(*p)++;
		}
		if (quote_count % 2 != 0)
			printf("not match quotes\n");
		(*tokens)[*num].type = TOKEN_QUOTE;
		(*tokens)[*num].value = ft_strndup(begin, (*p - begin));
		(*num)++;
		(*p)++;
	}
}
