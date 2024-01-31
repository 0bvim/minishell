/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:22:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/31 17:26:30 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_token(void *p_token)
{
	t_token	*token;

	token = p_token;
	if (token->str)
	{
		free(token->str);
		token->str = NULL;
	}
	free(token);
}

t_list	*token_list_holder(t_list *tokens)
{
	static t_list	*lst_address;

	if (tokens)
		lst_address = tokens;
	return (lst_address);
}

void	panic_tokenizer(int error, char *msg)
{
	t_list	*tokens;

	tokens = token_list_holder(NULL);
	if (tokens)
		ft_lstclear(tokens, free_token);
	if (msg)
		ft_putendl_fd(msg, 2);
	last_exit_status(error);
}
