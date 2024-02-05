/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirs_expansions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:28:25 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/05 13:36:34 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*tokens_to_str(t_list *tokens)
{
	t_element	*el;
	t_token		*token;
	char		*str;

	expansions(tokens);
	el = tokens->first;
	str = NULL;
	if (el)
		str = ft_calloc(1, sizeof(char));
	while (el && str)
	{
		token = el->content;
		str = ft_strmerge(str, token->str);
		token->str = NULL;
		el = el->next;
	}
	return (str);
}

void	substitute_first_token_str(t_list *tokens)
{
	t_token	*token;
	char	*str;

	token = tokens->first->content;
	str = tokens_to_str(tokens);
	if (!str)
		return ;
	if (token->str)
		free (token->str);
	token->str = str;
}
