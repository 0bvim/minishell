/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/12 21:25:08 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	input_validations(const char *str)
{
	if (!quotes_validation(str) || !parenthesis_validation(str))
		return (0);
	return (1);
}

static void	token_list_generator(t_list *tokens,
	const char *start, const char *mover)
{
	if (!*start)
		return ;
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
				break ;
			add_token(tokens, &start, &mover);
		}
	}
	if (mover > start)
		add_token(tokens, &start, &mover);
}

t_list	*tokenizer(const char *str)
{
	t_list		*tokens;

	if (!input_validations(str))
		return (NULL);
	tokens = ft_calloc(1, sizeof(t_list));
	if (!tokens)
		return (NULL);
	token_list_holder(tokens);
	ft_skip_spaces(&str);
	token_list_generator(tokens, str, str + 1);
	list_printer(tokens); //remove
	ft_lstclear(tokens, free); //remove
	return (tokens);
}
