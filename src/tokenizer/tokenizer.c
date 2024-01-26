/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/25 15:43:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	input_validations(const char *str)
{
	if (!*str)
		exit(EXIT_SUCCESS);
	if (!quotes_validation(str) || !parenthesis_validation(str))
		exit(errno);
}

static void	token_list_generator(t_list *tokens,
									const char *start,
									const char *mover)
{
	int	token;

	if (!*start || !*mover)
		return ;
	while (*mover)
	{
		token = which_token(start);
		if (*mover)
		{
			if (!add_special_token(tokens, &start, &mover, token))
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

	tokens = NULL;
	input_validations(str);
	tokens = ft_calloc(1, sizeof(t_list));
	if (!tokens)
		exit(errno);
	token_list_holder(tokens);
	ft_skip_spaces(&str);
	token_list_generator(tokens, str, str + 1);
	grammar_checker(tokens);
	return (tokens);
}
