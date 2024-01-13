/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:13:51 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 20:15:14 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	list_printer(t_list *tokens)
{
	t_element	*el;

	el = tokens->first;
	while (el)
	{
		printf("%s\n", (char *)el->content);
		el = el->next;
	}
}
