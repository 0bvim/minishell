/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:51:52 by nivicius          #+#    #+#             */
/*   Updated: 2024/02/15 02:41:01 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_infile(t_ast *node, t_token *token, int *file)
{
		set_fd_in(node);
		if (input_redir(node))
		{
			if (node->set_fd)
			{
				node->first_infile_err = 1;
				set_next_node_err(node);
				open_file_error(token->str);
			}
			*file = -1;
		}
}

void	handle_outfile(t_ast *node, int *file)
{
	set_fd_out(node);
	temp_fd(node);
	if (node->type == R_REDIR)
		*file = append_trunc(node, TRUN);
	else if (node->type == APPEND)
		*file = append_trunc(node, APEN);

}

void	outfile_error(t_ast *node, t_token *token)
{
	if (node->set_fd)
	{
		node->first_outfile_err = 1;
		set_next_node_err(node);
	}
	else
		open_file_error(token->str);
}

void	node_left_error(t_ast *node,t_token *token, const int *tmp, int *file)
{
		if (node->old_file == 0)
			unlink(token->str);
		node->error = 1;
		if (node->type == R_REDIR || node->type == APPEND)
			dup2(tmp[1], STDOUT_FILENO);
		if (node->type == L_REDIR|| node->type == HEREDOC)
			dup2(tmp[0], STDIN_FILENO);
		close_tmp(tmp);
		if (*file)
			close(*file);
		if (node->tmp_file)
		{
			close(node->fd);
			free(node->tmp_file);
		}
		last_exit_status(1);
}

void	after_ex(t_ast *node, int *file, const int *tmp)
{
	if (node->set_fd && !node->first_infile_err && *file != -1)
	{
		node->fd = open(node->tmp_file, O_RDONLY, 0644);
		char buff[1];
		while (read(node->fd, buff, 1))
			write(*file, buff, 1);
		close(node->fd);
		unlink(node->tmp_file);
		dup2(tmp[1], STDOUT_FILENO);
	}
	else
	{
		close(node->fd);
		dup2(tmp[1], STDOUT_FILENO);
		dup2(tmp[0], STDIN_FILENO);
	}
	if (*file != -1)
		close(*file);
	free(node->tmp_file);
}
