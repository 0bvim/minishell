/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:22:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 20:32:11 by bmoretti         ###   ########.fr       */
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
	exit (EXIT_FAILURE);
}
