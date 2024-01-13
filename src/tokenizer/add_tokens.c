/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tokens.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:20:35 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 20:38:51 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_token(t_list *tokens,
	const char **start, const char **mover)
{
	t_element	*el;
	char		*content;

	content = ft_strndup(*start, *mover - *start);
	if (!content)
		panic_tokenizer();
	el = ft_lstnewelement(content);
	if (!el)
		panic_tokenizer();
	ft_lstadd_back(tokens, el);
	ft_skip_spaces(mover);
	*start = *mover;
	if (**mover)
		(*mover)++;
}

void	add_quotes_token(t_list *tokens,
	const char **start, const char **mover)
{
	char		quote_type;

	quote_type = **start;
	(*mover)++;
	while (**mover != quote_type)
		(*mover)++;
	(*mover)++;
	add_token(tokens, start, mover);
}

void	add_symbols_token(t_list *tokens,
	const char **start, const char **mover)
{
	int	operator;

	operator = which_token(*start);
	if (operator == AND || operator == OR
		|| operator == HEREDOC || operator == APPEND)
		(*mover)++;
	add_token(tokens, start, mover);
}
