/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:08 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 16:20:05 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenizeParentheses(char *p, Token *tokens, int *numTokens)
{
	if (*p == '(')
	{
		tokens[*numTokens].type = TOKEN_LPAREN;
		tokens[*numTokens].value = "(";
		(*numTokens)++;
		p++;
	}
	else if (*p == ')')
	{
		tokens[*numTokens].type = TOKEN_RPAREN;
		tokens[*numTokens].value = ")";
		(*numTokens)++;
		p++;
	}
}


void tokenizeQuote(char *p, Token *tokens, int *numTokens)
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
		tokens[*numTokens].type = TOKEN_QUOTE;
		tokens[*numTokens].value = strndup(begin, p - begin);
		(*numTokens)++;
		p++;
	}
}
