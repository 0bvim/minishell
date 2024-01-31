/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grammar_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/31 17:44:23 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	grammar_checker(t_list *tokens)
{
	t_element	*el;

	if (!tokens || !tokens->first)
		panic_tokenizer(0, NULL);
	el = tokens->first;
	while (el)
	{
		if (redir_and_or_pipe_rule(el))
			return (1);
		el = el->next;
	}
	return (0);
}
