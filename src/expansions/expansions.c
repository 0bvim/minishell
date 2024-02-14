/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:33:04 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/14 17:01:34 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*merged_substitution(char *head, char *middle, char *tail,
	char **mover)
{
	char	*expansion;
	char	*expanded;
	ssize_t	delta;

	if (!ft_strncmp(middle, "?", 2))
		expansion = ft_itoa(last_exit_status(-1));
	else
		expansion = ft_strdup(getenv_or_blank(middle));
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
		if (*mover_2 == '?')
			mover_2++;
		else
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

void	token_expansion(void *p_token)
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
		if (*mover == '$' && *(mover + 1) && !ft_isspace(*(mover + 1)))
		{
			token->str = split_and_call_substitution(str, &mover);
			if (!token->str)
				exit (EXIT_FAILURE);
			free (str);
			str = token->str;
			mover--;
		}
		mover++;
	}
}

void	asterisk_expansion(t_list *tokens)
{
	t_element	*el;
	t_element	*next;
	t_token		*token;

	el = tokens->first;
	while (el)
	{
		token = el->content;
		if (token->type == ARGUMENT && ft_strchr(token->str, '*'))
		{
			asterisk(tokens, el);
			next = el->next;
			ft_lstdelone(tokens, el, free_token);
			el = next;
		}
		else
			el = el->next;
	}
}

void	expansions(t_list *tokens)
{
	asterisk_expansion(tokens);
	ft_lstiter(tokens, token_expansion);
}
