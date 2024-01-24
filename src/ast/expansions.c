/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:33:04 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/20 18:41:33 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*merged_substitution(char *head, char *middle, char *tail,
	char **mover)
{
	char	*expansion;
	char	*expanded;
	ssize_t	delta;

	expansion = ft_strdup(env_var_value(middle));
	free (middle);
	if (expansion)
	{
		delta = ft_strlen(head) + ft_strlen(expansion);
		expanded = ft_strmerge(ft_strmerge(head, expansion), tail);
		if (expanded)
			*mover = expanded + delta;
		return (expanded);
	}
	free (head);
	free (tail);
	return (NULL);
}

static char	*split_and_call_substitution(char *str, char **mover)
{
	char	*head;
	char	*middle;
	char	*tail;
	char	*mover_2;

	head = ft_strndup(str, *mover - str);
	if (head)
	{
		mover_2 = *mover + 1;
		while (*mover_2 && (ft_isalnum(*mover_2) || *mover_2 == '_' ))
			mover_2++;
		middle = ft_strndup(*mover + 1, mover_2 - (*mover + 1));
		if (middle)
		{
			tail = ft_strdup(mover_2);
			if (tail)
				return (merged_substitution(head, middle, tail, mover));
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
		if (*mover == '$' && *(mover + 1) && *(mover + 1) != '\"')
		{
			token->str = split_and_call_substitution(str, &mover);
			free (str);
			str = token->str;
			mover--;
		}
		mover++;
	}
}

void	expansions(t_list *tokens)
{
	ft_lstiter(tokens, token_expansion);
}