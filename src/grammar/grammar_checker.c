/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/15 18:39:28 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	skip_parenthesis(t_element	**el)
{
	if (((t_token *)(*el)->content)->type == L_PAREN)
	{
		while (((t_token *)(*el)->content)->type != R_PAREN)
			*el = (*el)->next;
		*el = (*el)->next;
	}
}

void	grammar_checker(t_list *tokens)
{
	t_element	*el;

	if (!tokens || !tokens->first)
		return ;
	el = tokens->first;
	while (el)
	{
		skip_parenthesis(&el);
		redir_and_or_pipe_rule(el);
		el = el->next;
	}
}
