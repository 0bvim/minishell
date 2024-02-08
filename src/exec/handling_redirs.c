/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/08 20:00:24 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	append_trunc(t_ast *node, int flag)
{
	t_token	*token;
	t_list	*right_tokens;

	node->left->type_prev = node->type;
	token = node->right->exec->first->content;
	right_tokens = node->right->exec;
	substitute_first_token_str(right_tokens);
	return (open(token->str, flag, 0644));
}

static int	open_file_error(char *file_name)
{
	if (!access(file_name, F_OK))
	{
		if (access(file_name, W_OK | R_OK))
		{
			ft_putstr_fd("minishell: Permission denied\n", 2);
			last_exit_status(1);
			return (1);
		}
		else
		{
			last_exit_status(0);
			return (0);
		}
	}
	else if (access(file_name, F_OK))
	{
		ft_putstr_fd("minishell: No such file or directory\n", 2);
		return (last_exit_status(1));

	}
	return (0);
}

static void	set_fd(t_ast *node, int token)
{
	static int	have_prev;

	if (have_prev)
		return ;
	if (is_redirect(node->type) && node->type_prev != token)
	{
		have_prev = 0;
		node->set_fd = 1;
	}
}

static int	input_redir(t_ast *node)
{
	t_list		*right_tokens;
	t_token		*token;
	int			file;

	right_tokens = node->right->exec;
	substitute_first_token_str(right_tokens);
	token = right_tokens->first->content;
	if (node->type == HEREDOC && token->type != QUOTE \
		&& token->type != DOUBLE_QUOTE)
		heredoc_expansion(token);
	file = open(token->str, O_RDONLY);
	if (file == -1)
		return (open_file_error(token->str));
	if (node->left && node->set_fd)
		dup2(file, STDIN_FILENO);
	close(file);
	if (node->type == HEREDOC)
		unlink(token->str);
	return (0);
}

void	temp_fd(t_ast *node, int flag)
{
	int	fd;

	fd = open("/temp/outfile", flag, 0644);
	node->fd = fd;
	dup2(fd, STDOUT_FILENO);
	close (fd);
}

void	handle_redirs(t_ast *node)
{
	t_token		*token;
	int			file;
	const int	tmp[2] = { dup(STDIN_FILENO), dup(STDOUT_FILENO) };

	file = 0;
	node->left->type_prev = node->type;
	if (node->type == L_REDIR || node->type == HEREDOC)
	{
		set_fd(node, L_REDIR);
		if (input_redir(node))
			return ;
	}
	else
	{
		set_fd(node, node->type);
		if (node->type == R_REDIR)
			temp_fd(node, TRUN);
		else
			temp_fd(node, APEN);
	}
	if (node->left)
		execution(node->left);
	if (node->left && node->left->success == 1)
	{
		node->success = 1;
		close (tmp[0]);
		close (tmp[1]);
		return ;
	}
	if (node->type == R_REDIR)
		file = append_trunc(node, TRUN);
	else if (node->type == APPEND)
		file = append_trunc(node, APEN);
	if (file == -1)
	{
		node->success = 1;
		if (node->type == R_REDIR || node->type == APPEND)
		{
			token = node->right->exec->first->content;
			open_file_error(token->str);
		}
	}
	if (node->type == R_REDIR || node->type == APPEND)
	{
		if (node->set_fd)
			//create function to get written content in fd of temp_fd and writes on right fd
			dup2(file, STDOUT_FILENO);
		close(file);
		dup2(tmp[1], STDOUT_FILENO);
		close(tmp[0]);
		close(tmp[1]);
	}
	if (node->type == L_REDIR || node->type == HEREDOC)
		dup2(tmp[0], STDIN_FILENO);
	close (tmp[0]);
	close (tmp[1]);
}
