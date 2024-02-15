/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_and_or.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:06:48 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/15 00:44:37 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_and(t_ast *and_node)
{
	execution(and_node->left);
	if (!last_exit_status(-1))
		execution(and_node->right);
}

static void	handle_or(t_ast *or_node)
{
	execution(or_node->left);
	if (last_exit_status(-1))
		execution(or_node->right);
}

void	handle_and_or(t_ast *node)
{
	if (node->type == AND)
		handle_and(node);
	else
		handle_or(node);
}
