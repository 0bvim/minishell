/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/15 19:40:26 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	input_validations(const char *str)
{
	if (*str)
	{
		if (!quotes_validation(str) || !parenthesis_validation(str))
			return (0);
	}
	return (1);
}

static void	token_list_generator(t_list *tokens,
									const char *start, const char *mover)
{
	int	token;

	if (!*start || !*mover)
		return ;
	while (*mover)
	{
		token = which_token(start);
		if (*mover)
		{
			if (token == QUOTE || token == DOUBLE_QUOTE)
				add_quotes_token(tokens, &start, &mover, token);
			else if (token != ARGUMENT)
				add_symbols_token(tokens, &start, &mover, token);
			else
			{
				while (*mover && !ft_isspace(*mover) && !ft_issymbol(*mover))
					mover++;
				if (mover == start)
					break ;
				add_token(tokens, &start, &mover, token);
			}
		}
	}
	if (mover > start)
		add_token(tokens, &start, &mover, which_token(start));
}

/*remove list_printer and ft_lstclear*/
t_list	*tokenizer(const char *str)
{
	t_list	*tokens;

	tokens = 0;
	if (*str)
	{
		if (!input_validations(str))
			return (NULL);
		tokens = ft_calloc(1, sizeof(t_list));
		if (!tokens)
			return (NULL);
		token_list_holder(tokens);
		if (*str)
			ft_skip_spaces(&str);
		if (*str + 1)
			token_list_generator(tokens, str, str + 1);
		list_printer(tokens);
		grammar_checker(tokens);
		ast_constructor(tokens);
		ft_lstclear(tokens, free_token);
	}
	return (tokens);
}
