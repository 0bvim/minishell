/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:12:23 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/04 19:57:44 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void tokenize_space(char **p);

t_token *tokenize(char *input)
{
	char	*p;
	t_token	*tokens;
	int		num_tokens;

	p = input;
	tokens = ft_calloc(MAX_NUM_TOKENS, sizeof(t_token));
	num_tokens = 0;

	while (*p != '\0')
	{
		tokenize_space(&p);
		tokenize_and(&p, &tokens, &num_tokens);
		tokenize_or(&p, &tokens, &num_tokens);
		tokenize_parentheses(&p, &tokens, &num_tokens);
		tokenize_quote(&p, &tokens, &num_tokens);
		tokenize_redirection(&p, &tokens, &num_tokens);
		tokenize_argument(&p, &tokens, &num_tokens);
	}
	return (tokens);
}

static void tokenize_space(char **p)
{
	while (ft_isspace(**p))
		(*p)++;
}
