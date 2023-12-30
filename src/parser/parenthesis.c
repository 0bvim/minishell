/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parenthesis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:19:08 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 16:29:20 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenizeParentheses(char *p, Token *tokens, int *num_tokens)
{
	if (*p == '(')
	{
		tokens[*num_tokens].type = TOKEN_LPAREN;
		tokens[*num_tokens].value = "(";
		(*num_tokens)++;
		p++;
	}
	else if (*p == ')')
	{
		tokens[*num_tokens].type = TOKEN_RPAREN;
		tokens[*num_tokens].value = ")";
		(*num_tokens)++;
		p++;
	}
}

void tokenizeQuote(char *p, Token *tokens, int *num_tokens)
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
		tokens[*num_tokens].type = TOKEN_QUOTE;
		tokens[*num_tokens].value = ft_strndup(begin, p - begin);
		(*num_tokens)++;
		p++;
	}
}
