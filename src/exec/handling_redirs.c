/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/15 02:58:56 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	append_trunc(t_ast *node, int flag)
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

int	open_file_error(char *file_name)
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

int	input_redir(t_ast *node)
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


void	handle_redirs(t_ast *node)
{
	t_token		*token;
	int			file;
	const int	tmp[2] = { dup(STDIN_FILENO), dup(STDOUT_FILENO) };

	init_redirs(node, &token, &file);
	if (is_redirect_in(node->type))
		handle_infile(node, token, &file);
	else
		handle_outfile(node, &file);
	if (file == -1)
	{
		if (file_err(node, token, tmp))
			return ;
	}
	if (node->left)
		execution(node->left);
	if (node->first_outfile_err || node->left->error)
	{
		if (node->set_fd || node->left->error)
			open_file_error(token->str);
	}
	if (node->left && node->left->error == 1)
	{
		node_left_error(node, token, tmp, &file);
		return ;
	}
	if (is_redirect_out(node->type))
		after_ex(node, &file, tmp);
	if (is_redirect_in(node->type))
		infile_after(node, tmp);
	close_tmp(tmp);
	return;
}
