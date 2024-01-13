/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:13:51 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/13 15:51:04 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	list_printer(t_list *tokens)
{
	t_element	*el;
	t_token		*token;

	el = tokens->first;
	while (el)
	{
		token = el->content;
		printf("%s\n", token->str);
		el = el->next;
	}
}
