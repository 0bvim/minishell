/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:51:30 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 19:47:41 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	split_and_add(const char *to_split, t_list *tokens, t_element *el)
{
	char	**splitted;
	t_token	*new_token;
	int		i;

	splitted = ft_split(to_split, ' ');
	if (!splitted)
		return ;
	i = -1;
	while (splitted[++i])
	{
		new_token = ft_calloc(1, sizeof(t_token));
		if (!new_token)
			break ;
		new_token->str = ft_strdup(splitted[i]);
		if (!new_token->str)
		{
			free (new_token);
			break ;
		}
		new_token->next_char = ' ';
		ft_lstadd_before(tokens, el, ft_lstnewelement(new_token));
	}
	ft_clear_list(&splitted);
}

void	split_spaces(t_list *tokens)
{
	t_element	*el;
	t_token		*token;

	el = tokens->first;
	while (el)
	{
		token = el->content;
		if (!ft_strchr(token->str, ' ') || is_quotes(token->type))
		{
			el = el->next;
			continue ;
		}
		split_and_add(token->str, tokens, el);
		if (el->next)
		{
			el = el->next;
			ft_lstdelone(tokens, el->prev, free_token);
		}
		else
		{
			ft_lstdelone(tokens, el, free_token);
			break ;
		}
	}
}
