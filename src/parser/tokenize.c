/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/30 01:43:43 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void tokenize_space(char *p);

Token *tokenize(char *input)
{
	char	*p;
	Token	*tokens;
	int		num_tokens;

	p = input;
	tokens = malloc(MAX_NUM_TOKENS * sizeof(Token));
	num_tokens = 0;

	while (*p != '\0')
	{
		tokenize_space(p);
		tokenize_and(p, tokens, &num_tokens);
		tokenize_or(p, tokens, &num_tokens);
		tokenize_parentheses(p, tokens, &num_tokens);
		tokenize_quote(p, tokens, &num_tokens);
		tokenize_argument(p, tokens, &num_tokens);
	}
	return (tokens);
}

static void tokenize_space(char *p)
{
	while (*p == ' ' || *p == '\t' || *p == '\n')
	{
		p++;
	}
}
