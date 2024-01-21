/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:22:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/20 21:16:51 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_token(void *p_token)
{
	t_token	*token;

	token = p_token;
	if (token->str)
		free (token->str);
	free (token);
}

t_list	*token_list_holder(t_list *tokens)
{
	static t_list	*lst_address;

	if (tokens)
		lst_address = tokens;
	return (lst_address);
}

void	panic_tokenizer(char *error_msg)
{
	t_list	*tokens;

	tokens = token_list_holder(NULL);
	if (tokens)
		ft_lstclear(tokens, free_token);
	if (error_msg)
		ft_putendl_fd(error_msg, 2);
	exit (EXIT_FAILURE);
}
