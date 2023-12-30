/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parentheses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:08 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/30 01:16:23 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenize_parentheses(char *p, Token *tokens, int *num)
{
	if (*p == '(')
	{
		tokens[*num].type = TOKEN_LPAREN;
		tokens[*num].value = "(";
		(*num)++;
		p++;
	}
	else if (*p == ')')
	{
		tokens[*num].type = TOKEN_RPAREN;
		tokens[*num].value = ")";
		(*num)++;
		p++;
	}
}

void tokenize_quote(char *p, Token *tokens, int *num)
{
	if (*p == '"' || *p == '\'')
	{
		char quote = *p;
		char *begin = ++p;
		int quoteCount = 1;
		while (*p && quoteCount > 0)
		{
			if (*p == quote)
				quoteCount++;
			if (*p == quote)
				quoteCount--;
			p++;
		}
		if (quoteCount != 0)
		{
			// Handle error: unmatched quote
		}
		tokens[*num].type = TOKEN_QUOTE;
		tokens[*num].value = ft_strndup(begin, p - begin);
		(*num)++;
		p++;
	}
}
