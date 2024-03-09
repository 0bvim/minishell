/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:51:07 by bmoretti          #+#    #+#             */
/*   Updated: 2024/03/09 14:01:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_fork(int status)
{
	static int	on_fork;

	if (status == 1)
		on_fork = status;
	rl_clear_history();
	return (on_fork);
}

void	dup_fun(t_ast *node, int outin)
{
	if (node->fd != -1)
	{
		dup2(node->fd, outin);
		close(node->fd);
	}
}
