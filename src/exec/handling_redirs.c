/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/22 00:49:11 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	expand_redirs(t_list *right_tokens);

static void	open_file_error(char *file_name)
{
	if (last_exit_status(-1))
		return ;
	if (!access(file_name, F_OK) && access(file_name, W_OK | R_OK))
	{
		ft_putstr_fd("minishell: Permission denied\n", 2);
		last_exit_status(1);
	}
	else if (access(file_name, F_OK))
	{
		ft_putstr_fd("minishell: No such file or directory\n", 2);
		last_exit_status(1);
	}
}

static void	handle_outfile(t_ast *node)
{
	t_token	*token;
	t_list	*right_tokens;

	right_tokens = node->right->exec;
	if (!expand_redirs(right_tokens))
	{
		node->fd = -1;
		return ;
	}
	token = right_tokens->first->content;
	if (node->type == R_REDIR)
		node->fd = open(token->str, TRUN, 0666);
	else if (node->type == APPEND)
		node->fd = open(token->str, APEN, 0666);
	if ((node->fd == -1) && last_exit_status(-1))
		last_exit_status(0);
	open_file_error(token->str);
}

void	handle_infile(t_ast *node)
{
	t_list	*right_tokens;
	t_token	*token;

	right_tokens = node->right->exec;
	if (!expand_redirs(right_tokens) && !(node->type == HEREDOC))
	{
		node->fd = -1;
		return ;
	}
	token = right_tokens->first->content;
	if (node->type == HEREDOC && token->type != QUOTE \
		&& token->type != DOUBLE_QUOTE)
		heredoc_expansion(token);
	node->fd = open(token->str, O_RDONLY);
	if (node->fd == -1 && last_exit_status(-1))
		last_exit_status(0);
	open_file_error(token->str);
}

void	open_dup_close(t_ast *node)
{
	if (is_redirect(node->left->type))
		open_dup_close(node->left);
	if (is_redirect_out(node->type)
		&& ((node->fd != -1 && node->left->fd != -1) && !last_exit_status(-1)))
	{
		handle_outfile(node);
		if (node->fd != -1)
		{
			dup2(node->fd, STDOUT_FILENO);
			close(node->fd);
		}
	}
	else if (is_redirect_in(node->type)
		&& (node->left->fd != -1 || !last_exit_status(-1)))
	{
		handle_infile(node);
		if (node->fd != -1)
		{
			dup2(node->fd, STDIN_FILENO);
			close(node->fd);
		}
		if (node->type == HEREDOC)
			unlink(node->right->exec->first->content);
	}
}

void	handle_redirs(t_ast *node)
{
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	if (!node->fd)
		open_dup_close(node);
	if (last_exit_status(-1) && node->fd == -1)
	{
		dup_close_tmp(tmp);
		return ;
	}
	fd_keeper(tmp, node->fd, 0);
	execution(node->left);
	dup_close_tmp(tmp);
}
