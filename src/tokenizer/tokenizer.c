/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/03 02:49:29 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	token_list_generator(t_list *tokens,
									const char *start,
									const char *mover)
{
	int	token;

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

t_list	*tokenizer(const char *str)
{
	t_list	*tokens;

	ft_skip_spaces(&str);
	if (!*str)
		return (NULL);
	if (!quotes_validation(str) || !parenthesis_validation(str))
	{
		last_exit_status(2);
		return (NULL);
	}
	tokens = ft_calloc(1, sizeof(t_list));
	if (!tokens)
		return (NULL);
	token_list_holder(tokens, 0);
	token_list_generator(tokens, str, str + 1);
	return (tokens);
}
