/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_redirs_pipe_rule.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/31 17:41:23 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_redirect(int type)
{
	return (type == L_REDIR || type == R_REDIR
		|| type == HEREDOC || type == APPEND);
}

static int	is_and_or(int type)
{
	return (type == AND || type == OR);
}

/*remember to change ft_putstr for panic function*/
int	redir_and_or_pipe_rule(t_element *el)
{
	int		type;
	int		prev_type;

	type = ((t_token *)el->content)->type;
	if (el->prev)
		prev_type = ((t_token *)el->prev->content)->type;
	else
		prev_type = -1;
	if (is_and_or(type) || type == PIPE)
	{
		if (prev_type == -1)
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
	return (0);
}
