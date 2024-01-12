/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/12 19:06:45 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*token_list_holder(t_list *tokens)
{
	static t_list	*lst_address;

	if (tokens)
		lst_address = tokens;
	return (lst_address);
}

void	panic_tokenizer(void)
{
	t_list	*tokens;

	tokens = token_list_holder(NULL);
	if (tokens)
		ft_lstclear(tokens, free);
}

static int	which_token(const char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (AND);
	if (!ft_strncmp(str, "||", 2))
		return (OR);
	if (!ft_strncmp(str, "<<", 2))
		return (HEREDOC);
	if (!ft_strncmp(str, ">>", 2))
		return (APPEND);
	if (*str == '|')
		return (PIPE);
	if (*str == '$')
		return (DOLLAR);
	if (*str == '(')
		return (L_PAREN);
	if (*str == ')')
		return (R_PAREN);
	if (*str == '\'')
		return (QUOTE);
	if (*str == '"')
		return (DOUBLE_QUOTE);
	if (*str == '<')
		return (L_REDIR);
	if (*str == '>')
		return (R_REDIR);
	return (ARGUMENT);
}

void	count_quotes(const char *str, int *single_quotes, int *double_quotes)
{
	char	quote_type;

	*single_quotes = 0;
	*double_quotes = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			quote_type = *str;
			if (quote_type == '\'')
				(*single_quotes)++;
			else
				(*double_quotes)++;
			str++;
			while (*str && *str != quote_type)
				str++;
			if (*str == quote_type && *str == '\'')
				(*single_quotes)++;
			else if (*str == quote_type && *str == '"')
				(*double_quotes)++;
		}
		str++;
	}
}

int	quotes_validation(const char *str)
{
	int		single_quotes;
	int		double_quotes;

	count_quotes(str, &single_quotes, &double_quotes);
	if (single_quotes % 2 || double_quotes % 2)
		return (0);
	return (1);
}

void	add_token(t_list *tokens, const char **start, const char **mover)
{
	t_element	*el;
	char		*content;

	content = ft_strndup(*start, *mover - *start);
	if (!content)
		return ; //panic
	el = ft_lstnewelement(content);
	if (!el)
		return ; //panic
	ft_lstadd_back(tokens, el);
	ft_skip_spaces(mover);
	*start = *mover;
	(*mover)++;
}

void	add_quotes_token(t_list *tokens, const char **start, const char **mover)
{
	char		quote_type;

	quote_type = **start;
	(*mover)++;
	while (**mover != quote_type)
		(*mover)++;
	(*mover)++;
	add_token(tokens, start, mover);
}

void	add_symbols_token(t_list *tokens, const char **start, const char **mover)
{
	int	operator;

	operator = which_token(*start);
	if (operator == AND || operator == OR
		|| operator == HEREDOC || operator == APPEND)
		(*mover)++;
	(*mover)++;
	add_token(tokens, start, mover);
}

void	list_generator(t_list *tokens, const char *start, const char *mover)
{
	while (*mover)
	{
		if (*start == '\'' || *start == '"')
			add_quotes_token(tokens, &start, &mover);
		else if (ft_issymbol(*start))
			add_symbols_token(tokens, &start, &mover);
		else
		{
			while (*mover && !ft_isspace(*mover) && !ft_issymbol(*mover))
				mover++;
			if (mover == start)
				break;
			add_token(tokens, &start, &mover);
		}
	}
}

void	list_printer(t_list *tokens) //debug purposes only
{
	t_element	*el;

	el = tokens->first;
	while (el)
	{
		printf("%s\n", (char *)el->content);
		el = el->next;
	}
}

t_list	*tokenizer(const char *str)
{
	t_list		*tokens;

	if (!quotes_validation(str))
		return (NULL);
	tokens = ft_calloc(1, sizeof(t_list));
	if (!tokens)
		return (NULL);
	token_list_holder(tokens);
	ft_skip_spaces(&str);
	list_generator(tokens, str, str);
	list_printer(tokens); //remove
	panic_tokenizer(); //remove
	return (tokens);
}
