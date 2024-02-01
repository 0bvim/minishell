/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_redirs_pipe_rule.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/01 12:28:29 by brmoretti        ###   ########.fr       */
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
	else if (is_redirect(prev_type) || is_and_or(prev_type)
		|| prev_type == PIPE)
		panic_tokenizer(2, "Invalid syntax");
	else
		return (0);
	return (1);
}
