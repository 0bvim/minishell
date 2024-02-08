/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 13:53:03 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/08 10:50:12 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_element	*search_and_or(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (token->type == AND || token->type == OR)
			return (el);
		el = el->prev;
	}
	return (NULL);
}

t_element	*search_pipe(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (token->type == PIPE)
			return (el);
		el = el->prev;
	}
	return (NULL);
}

t_element	*search_outfile_redir(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (token->type == R_REDIR || token->type == APPEND)
			return (el);
		el = el->prev;
	}
	return (NULL);
}

t_element	*search_infile_redir(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->first;
	while (el)
	{
		token = el->content;
		if (token->type == L_REDIR || token->type == HEREDOC)
			return (el);
		el = el->next;
	}
	return (NULL);
}

t_element	*search_redir(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (is_redirect(token->type))
			return (el);
		el = el->prev;
	}
	return (NULL);
}

// t_element	*search_infile_redir(t_list *tokens)
// {
// 	t_token		*token;
// 	t_element	*el;

// 	el = tokens->first;
// 	while (el)
// 	{
// 		token = el->content;
// 		if (token->type == R_REDIR ||token->type == APPEND)
// 		{
// 			el = tokens->last;
// 			while (el)
// 			{
// 				token = el->content;
// 				if (token->type == R_REDIR ||token->type == APPEND)
// 					return (el);
// 				el = el->prev;
// 			}
// 		}
// 		if (token->type == L_REDIR || token->type == HEREDOC)
// 			return (el);
// 		el = el->next;
// 	}
// 	return (NULL);
// }
