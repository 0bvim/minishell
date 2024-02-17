/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/17 02:04:04 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	append_trunc(t_ast *node, int flag)
{
	t_token	*token;
	t_list	*right_tokens;
	int		file;

	token = node->right->exec->first->content;
	right_tokens = node->right->exec;
	substitute_first_token_str(right_tokens);
	file = open(token->str, flag, 0666);
	open_file_error(token->str);
	return (file);
}

int	open_file_error(char *file_name)
{
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

// int	input_redir(t_ast *node)
// {
// 	t_list		*right_tokens;
// 	t_token		*token;
// 	int			file;
//
// 	right_tokens = node->right->exec;
// 	substitute_first_token_str(right_tokens);
// 	token = right_tokens->first->content;
// 	if (node->type == HEREDOC && token->type != QUOTE \
// 		&& token->type != DOUBLE_QUOTE)
// 		heredoc_expansion(token);
// 	file = open(token->str, O_RDONLY);
// 	if (file == -1 && !node->first_infile_err)
// 		return (open_file_error(token->str));
// 	else if (file == -1)
// 		return (last_exit_status(1));
// 	if (node->left && node->set_fd)
// 		dup2(file, STDIN_FILENO);
// 	close(file);
// 	if (node->type == HEREDOC)
// 		unlink(token->str);
// 	return (0);
// }

// void	before_recursion(t_ast *node, t_token **token, int *file)
// {
// 	init_redirs(node, token, file);
// 	if (is_redirect_in(node->type))
// 	{
// 		set_fd_in(node);
// 		handle_infile(node, *token, file);
// 	}
// 	else
// 	{
// 		set_fd_out(node);
// 		temp_fd(node);
// 		handle_outfile(node, file);
// 	}
// }

void	open_dup_close(t_ast *node)
{
	if (is_redirect(node->left->type))
		open_dup_close(node->left);
	if(is_redirect_out(node->type) && !last_exit_status(-1))
	{
		handle_outfile(node);
		if (node->fd != -1)
		{
			dup2(node->fd, STDOUT_FILENO);
			close(node->fd);
		}
	}
}

void	handle_redirs(t_ast *node)
{
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	if (!node->fd)
		open_dup_close(node);
	if (last_exit_status(-1))
	{
		dup2(tmp[1], STDOUT_FILENO);
		dup2(tmp[0], STDIN_FILENO);
		close_tmp(tmp);
		return ;
	}
	execution(node->left);
	dup2(tmp[1], STDOUT_FILENO);
	dup2(tmp[0], STDIN_FILENO);
	close_tmp(tmp);
}

// void	handle_redirs(t_ast *node)
// {
// 	t_token		*token;
// 	int			file;
// 	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};
//
// 	before_recursion(node, &token, &file);
// 	if (node->left)
// 		execution(node->left);
// 	// if (is_redirect_in(node->type))
// 	// 	handle_infile(node, token, &file);
// 	// else
// 	// 	handle_outfile(node, &file);
// 	if (file == -1)
// 		if (file_err(node, token, tmp))
// 			return ;
// 	if (node->first_outfile_err || node->left->error)
// 		if (node->set_fd || node->left->error)
// 			open_file_error(token->str);
// 	if (node->left && node->left->error == 1)
// 	{
// 		node_left_error(node, token, tmp, &file);
// 		return ;
// 	}
// 	seek_and_destroy(node, &file, tmp);
// 	close_tmp(tmp);
// 	return ;
// }
