/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 16:17:02 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void tokenize_space(char *p, Token *tokens, int *num);

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
		tokenize_space(p, tokens, num_tokens);
		tokenize_and(p, tokens, num_tokens);
	}
	return (tokens);
}

static void tokenize_space(char *p, Token *tokens, int *num)
{
	while (*p == ' ' || *p == '\t' || *p == '\n')
	{
		p++;
	}
}
