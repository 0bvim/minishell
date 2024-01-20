/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:33:04 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/20 13:07:09 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static char	*merged_substitution(char *head, char *middle, char *tail, char **split)
{
	char	*expansion;
	char	*expanded;
	size_t	delta;

	expansion = ft_strdup(env_var_value(middle));
	free (middle);
	if (expansion)
	{
		delta = ft_strlen(head) + ft_strlen(expansion);
		expanded = ft_strmerge(ft_strmerge(head, expansion), tail);
		if (expanded)
			*split = expanded + delta;
		return (expanded);
	}
	free (head);
	free (tail);
	return (NULL);
}

static char	*split_and_call_substitution(char *str, char **split)
{
	char	*head;
	char	*middle;
	char	*tail;
	char	*mover;

	head = ft_strndup(str, *split - str);
	if (head)
	{
		mover = *split + 1;
		while (*mover && ft_isalnum(*mover))
			mover++;
		middle = ft_strndup(*split + 1, mover - (*split + 1));
		if (middle)
		{
			tail = ft_strdup(mover);
			if (tail)
				return (merged_substitution(head, middle, tail, split));
			free (middle);
		}
		free (head);
	}
	return (NULL);
}

static void	token_expansion(void *p_token)
{
	t_token	*token;
	char	*str;
	char	*mover;

	token = p_token;
	if (token->type == QUOTE)
		return ;
	str = token->str;
	mover = str;
	while (*mover)
	{
		if (*mover == '$' && *(mover + 1))
		{
			token->str = split_and_call_substitution(str, &mover);
			free (str);
			str = token->str;
		}
		mover++;
	}
}

void	expansions(t_list *tokens)
{
	ft_lstiter(tokens, token_expansion);
}