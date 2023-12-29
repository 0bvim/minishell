/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 16:20:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenizeAnd(char *p, Token *tokens, int *numTokens)
{
	if (*p == '&' && *(p + 1) == '&')
	{
		tokens[*numTokens].type = TOKEN_AND;
		tokens[*numTokens].value = "&&";
		(*numTokens)++;
		p += 2;
	}
}


void tokenizeOr(char *p, Token *tokens, int *numTokens)
{
	if (*p == '|' && *(p + 1) == '|')
	{
		tokens[*numTokens].type = TOKEN_OR;
		tokens[*numTokens].value = "||";
		(*numTokens)++;
		p += 2;
	}
}
