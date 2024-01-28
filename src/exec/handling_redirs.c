/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/28 14:36:39 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	input_redir(t_ast *node_pipe);

void	handle_redirs(t_ast *node_pipe)
{
	t_token	*token;
	int		file = 0;

	token = node_pipe->right->exec->first->content;
	if (node_pipe->type == L_REDIR)
		input_redir(node_pipe);
	else if (node_pipe->type == R_REDIR)
		file = open(token->str, TRUN, 0644);
	else if (node_pipe->type == APPEND)
		file = open(token->str,  APEN, 0644);
	if (node_pipe->type == R_REDIR || node_pipe->type == APPEND)
	{
		if (file == -1)
			exit(1); //panic
		dup2(file, STDOUT_FILENO);
		close(file);
		execution(node_pipe->left);
	}
}

static void	input_redir(t_ast *node_pipe)
{
	t_token	*token;
	int		file = 0;

	token = node_pipe->right->exec->first->content;
	file = open(token->str, O_RDONLY);
	if (file == -1)
		exit(1); //panic
	dup2(file, 0);
	execution(node_pipe->left);
	close(file);
}
