/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/26 21:56:55 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_redirs(t_ast *node_pipe)
{
	int	file;

	file = open(((t_token *)node_pipe->right->exec->first->content)->str, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (file == -1)
		exit(1); //panic
	dup2(file, STDOUT_FILENO);
	close(file);
	execution(node_pipe->left);;
}
