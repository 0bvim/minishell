/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:33:04 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 17:50:45 by nivicius         ###   ########.fr       */
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
	split_tk_str(tokens);
}

int	is_quotes(int type)
{
	return (type == QUOTE || type == DOUBLE_QUOTE);
}

void	split_tk_str(t_list *toks)
{
	t_element	*el;
	t_token		*tk;
	t_token		*new_token;
	char		**splited;
	int			i;
	
	el = toks->first;
	i = -1;
	while (el)
	{
		tk = el->content;
		if (!ft_strchr(tk->str, ' ') || is_quotes(tk->type))
		{
			el = el->next;
			continue;
		}
		splited = ft_split(tk->str, 32);
		while (splited[++i])
		{
			new_token = ft_calloc(1, sizeof(t_token));
			new_token->type = tk->type;
			new_token->next_char = ' ';
			new_token->str = ft_strdup(tk->str);
			ft_lstadd_before(toks, el,ft_lstnewelement(new_token));
		}
		ft_clear_list(&splited);
		if (el->next)
		{
			el = el->next;
			ft_lstdelone(toks, el->prev, free_token);
		}
		else
		{
			ft_lstdelone(toks, el, free_token);
			break;
		}
	}
}
