/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/18 11:05:48 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redir_and_or_pipe_rule(t_element *el)
{
	int		type;
	int		prev_type;

	type = ((t_token *)el->content)->type;
	if (!(is_and_or(type) || type == PIPE || is_redirect(type)))
		return (0);
	if (el->prev)
		prev_type = ((t_token *)el->prev->content)->type;
	else
		prev_type = -1;
	if (prev_type == -1 && !is_redirect(type))
		panic_tokenizer(2, "Invalid token begining the line");
	else if (!el->next)
		panic_tokenizer(2, "Invalid token at the end of the line");
	else if (!is_redirect(type)
		&& (is_redirect(prev_type) || is_and_or(prev_type)
			|| prev_type == PIPE))
		panic_tokenizer(2, "Invalid syntax");
	else if (is_redirect(type) && is_redirect(prev_type))
		panic_tokenizer(2, "Invalid syntax");
	else
		return (0);
	return (1);
}

int	check_block_grammar(t_element *el)
{
	t_list	*tokens_backup;
	t_list	*block_tokens;
	int		grammar;

	tokens_backup = token_list_holder(NULL, 0, 0);
	block_tokens = tokenizer(((t_token *)el->content)->str);
	ft_lstiter(block_tokens, trim_edges);
	grammar = grammar_checker(block_tokens);
	token_list_holder(NULL, 1, 0);
	token_list_holder(tokens_backup, 0, 0);
	if (grammar)
	{
		panic_tokenizer(2, NULL);
		return (1);
	}
	return (0);
}

int	block_rule(t_element *el)
{
	int		prev_type;
	int		next_type;

	if (((t_token *)el->content)->type != BLOCK)
		return (0);
	prev_type = -1;
	next_type = -1;
	if (el->prev)
		prev_type = ((t_token *)el->prev->content)->type;
	if (el->next)
		next_type = ((t_token *)el->next->content)->type;
	if (!((prev_type == -1 || is_metacharacter(prev_type))
			&& (next_type == -1 || is_metacharacter(next_type))))
	{
		panic_tokenizer(2, "syntax error near unexpected token");
		return (1);
	}
	if (check_block_grammar(el))
	{
		token_list_holder(NULL, 1, 0);
		return (1);
	}
	return (0);
}
