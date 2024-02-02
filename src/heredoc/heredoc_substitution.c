/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_substitution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:12:17 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/02 18:16:50 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	heredoc_substitution(t_list *tokens)
{
	t_element	*el;
	t_token		*token;

	el = tokens->first;
	while (el)
	{
		token = el->content;
		if (token->type == HEREDOC)
			heredoc(el->next);
		el = el->next;
	}
}
