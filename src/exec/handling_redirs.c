/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/08 23:43:37y nivicius         ###   ########.fr       */
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
	if (!access(token->str, F_OK))
		node->old_file = 1;
	return (open(token->str, flag, 0644));
}

static int	open_file_error(char *file_name)
{
	if (last_exit_status(-1) == 1)
		return (1);
	if (!access(file_name, F_OK) && access(file_name, W_OK | R_OK))
	{
		ft_putstr_fd("minishell: Permission denied\n", 2);
		return (last_exit_status(1));
	}
	else if (access(file_name, F_OK))
	{
		ft_putstr_fd("minishell: No such file or directory\n", 2);
		return (last_exit_status(1));
	}
	return (0);
}

static int	is_redirect_in(int type)
{
	return (type == L_REDIR || type == HEREDOC);
}

static int	is_redirect_out(int type)
{
	return (type == R_REDIR || type == APPEND);
}

static void	set_next_node_err(t_ast *node)
{
	t_ast	*tmp;

	tmp = 0;
	if (node->left)
		tmp = node->left;
	while (tmp)
	{
		if (is_redirect_in(tmp->type))
			tmp->first_infile_err = node->first_infile_err;
		else if (is_redirect_out(tmp->type))
			tmp->first_outfile_err = node->first_outfile_err;
		tmp = tmp->left;
	}
}

static void	set_next_node(t_ast *node)
{
	t_ast	*tmp;

	tmp = 0;
	if (node->left)
		tmp = node->left;
	while (tmp)
	{
		if (tmp->type == node->type)
		{
			if (is_redirect_in(node->type))
				tmp->infile_set = 1;
			else if (is_redirect_out(node->type))
				tmp->outfile_set = 1;
		}
		tmp = tmp->left;
	}
}

static void	set_fd_out(t_ast *node, int token)
{
	static int	have_prev;

	(void)token;
	if (have_prev || node->outfile_set)
		return ;
	if (is_redirect(node->type) && !is_redirect_out(node->type_prev))
	{
		have_prev = 0;
		node->set_fd = 1;
		set_next_node(node);
	}
}

static void	set_fd_in(t_ast *node, int token)
{
	static int	have_prev;

	(void)token;
	if (have_prev || node->infile_set)
		return ;
	if (is_redirect(node->type) && !is_redirect_in(node->type_prev))
	{
		have_prev = 0;
		node->set_fd = 1;
		set_next_node(node);
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
	if (file == -1 && !node->first_infile_err)
		return (open_file_error(token->str));
	else if (file == -1)
		return (last_exit_status(1));
	if (node->left && node->set_fd)
		dup2(file, STDIN_FILENO);
	close(file);
	if (node->type == HEREDOC)
		unlink(token->str);
	return (0);
}

void	temp_fd(t_ast *node)
{
	int	fd;

	if (!node->set_fd)
		return ;
	fd = open("/tmp/outfile", O_CREAT | O_TRUNC | O_RDWR, 0644);
	node->fd = fd;
	dup2(fd, STDOUT_FILENO);
	close (fd);
}

static int	check_infile(t_ast *node)
{
	t_ast	*tmp;

	tmp = node->left;
	while (tmp)
	{
		if (is_redirect(tmp->type))
			return (0);
		tmp = tmp->left;	
	}
	return (1);
}

void	handle_redirs(t_ast *node)
{
	t_token		*token;
	int			file;
	const int	tmp[2] = { dup(STDIN_FILENO), dup(STDOUT_FILENO) };

	file = 0;
	node->left->type_prev = node->type;
	token = node->right->exec->first->content;
	if (node->type == L_REDIR || node->type == HEREDOC)
	{
		set_fd_in(node, node->type);
		if (input_redir(node))
		{
			if (node->set_fd)
			{
				node->first_infile_err = 1;
				set_next_node_err(node);
				open_file_error(token->str);
			}
			file = -1;
		}
	}
	else
	{
		set_fd_out(node, node->type);
		temp_fd(node);
	}
	if (node->type == R_REDIR)
		file = append_trunc(node, TRUN);
	else if (node->type == APPEND)
		file = append_trunc(node, APEN);
	if (file == -1)
	{
		node->error = 1;
		if (is_redirect_out(node->type))
		{
			if (node->set_fd)
			{
				node->first_outfile_err = 1;
				set_next_node_err(node);
			}
		}
		if (check_infile(node))
			return ;
		else if (node->left->first_infile_err)
		{
			close(node->fd);
			dup2(tmp[0], STDIN_FILENO);
			close(tmp[0]);
			close(tmp[1]);
			return ;
		}
	}
	if (node->left)
		execution(node->left);
	if (node->first_outfile_err || node->left->error)
	{
		open_file_error(token->str);
		last_exit_status(1);
	}
	if (node->left && node->left->error == 1)
	{
		if (node->old_file == 0)
			unlink(token->str);
		node->error = 1;
		if (node->type == R_REDIR || node->type == APPEND)
			dup2(tmp[1], STDOUT_FILENO);
		if (node->type == L_REDIR|| node->type == HEREDOC)
			dup2(tmp[0], STDIN_FILENO);
		close (tmp[0]);
		close (tmp[1]);
		if (file)
			close(file);
		return ;
	}
	if (node->type == R_REDIR || node->type == APPEND)
	{
		if (node->set_fd && !node->first_infile_err)
		{
			node->fd = open("/tmp/outfile", O_RDONLY, 0644);
			char buff[1];
			while (read(node->fd, buff, 1))
				write(file, buff, 1);
			close(node->fd);
			unlink("/tmp/outfile");
			dup2(tmp[1], STDOUT_FILENO);
		}
		else
		{
			close(node->fd);
			dup2(tmp[1], STDOUT_FILENO);
			dup2(tmp[0], STDIN_FILENO);
		}
		close(file);
	}
	if (node->type == L_REDIR || node->type == HEREDOC)
		dup2(tmp[0], STDIN_FILENO);
	close (tmp[0]);
	close (tmp[1]);
	if (node->first_outfile_err)
		last_exit_status(1);
}
