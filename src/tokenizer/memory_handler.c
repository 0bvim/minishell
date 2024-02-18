/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:22:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/18 11:02:47 by brmoretti        ###   ########.fr       */
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

t_list	*token_list_holder(t_list *tokens, int to_free, int to_null)
{
	static t_list	*lst_address;

	if (tokens)
		lst_address = tokens;
	if (to_null)
		lst_address = NULL;
	//printf("lst_address: %p\n", (void *)lst_address);
	if (lst_address && to_free)
	{
		ft_lstclear(lst_address, free_token);
		lst_address = NULL;
	}
	return (lst_address);
}

void	panic_tokenizer(int error, char *msg)
{
	token_list_holder(NULL, 1, 0);
	if (msg)
		ft_putendl_fd(msg, 2);
	last_exit_status(error);
}
