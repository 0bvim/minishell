/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/16 12:17:53 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_token(t_list *tokens,
				const char **start, const char **mover, int token_type)
{
	t_element	*el;
	t_token		*content;

	content = ft_calloc(1, sizeof(t_token));
	if (!content)
		panic_tokenizer(1, "memory allocation failure\n");
	content->str = ft_strndup(*start, *mover - *start);
	if (!content->str)
		panic_tokenizer(1, "memory allocation failure\n");
	content->type = token_type;
	content->next_char = **mover;
	el = ft_lstnewelement(content);
	if (!el)
		panic_tokenizer(1, "memory allocation failure\n");
	ft_lstadd_back(tokens, el);
	if (**mover)
		ft_skip_spaces(mover);
	*start = *mover;
	if (**mover)
		(*mover)++;
}

static void	add_quotes_token(t_list *tokens,
					const char **start, const char **mover, int token_type)
{
	char	quote_type;

	quote_type = **start;
	if (**mover)
		while (**mover != quote_type)
			(*mover)++;
	if (**mover)
		(*mover)++;
	add_token(tokens, start, mover, token_type);
}

static void	add_symbols_token(t_list *tokens,
					const char **start, const char **mover, int token_type)
{
	if (token_type == AND || token_type == OR || token_type == HEREDOC \
		|| token_type == APPEND)
		(*mover)++;
	add_token(tokens, start, mover, token_type);
}

static void	add_block_token(t_list *tokens,
					const char **start, const char **mover)
{
	//while (**mover && **mover != ')')
	//	(*mover)++;
	*mover = ft_strrchr(*mover, ')');
	if (**mover)
		(*mover)++;
	add_token(tokens, start, mover, BLOCK);
}

int	add_special_token(t_list *tokens,
					const char **start, const char **mover, int token_type)
{
	if (token_type == QUOTE || token_type == DOUBLE_QUOTE)
		add_quotes_token(tokens, start, mover, token_type);
	else if (token_type == L_PAREN)
		add_block_token(tokens, start, mover);
	else if (token_type != ARGUMENT && token_type != DOLLAR)
		add_symbols_token(tokens, start, mover, token_type);
	else
		return (0);
	return (1);
}
