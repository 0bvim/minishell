/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 16:23:15 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenizeAnd(char *p, Token *tokens, int *num_tokens)
{
	if (*p == '&' && *(p + 1) == '&')
	{
		tokens[*num_tokens].type = TOKEN_AND;
		tokens[*num_tokens].value = "&&";
		(*num_tokens)++;
		p += 2;
	}
}


void tokenizeOr(char *p, Token *tokens, int *num_tokens)
{
	if (*p == '|' && *(p + 1) == '|')
	{
		tokens[*num_tokens].type = TOKEN_OR;
		tokens[*num_tokens].value = "||";
		(*num_tokens)++;
		p += 2;
	}
}
