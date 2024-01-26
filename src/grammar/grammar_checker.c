/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/26 12:23:52 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	grammar_checker(t_list *tokens)
{
	t_element	*el;

	if (!tokens || !tokens->first)
		panic_tokenizer(0, NULL);
	el = tokens->first;
	while (el)
	{
		redir_and_or_pipe_rule(el);
		el = el->next;
	}
}
