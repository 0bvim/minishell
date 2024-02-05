/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/05 13:35:57 by brmoretti        ###   ########.fr       */
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

static void	open_file_error(char *file_name)
{
	if (!access(file_name, F_OK))
		ft_putstr_fd("minishell: Permission denied\n", 2);
	else
		ft_putstr_fd("minishell: No such file or directory\n", 2);
	last_exit_status(1);
}

static void	input_redir(t_ast *node)
{
	t_list		*right_tokens;
	t_token		*token;
	int			file;
	int			tmp;

	right_tokens = node->right->exec;
	substitute_first_token_str(right_tokens);
	token = right_tokens->first->content;
	if (node->type == HEREDOC && token->type != QUOTE \
		&& token->type != DOUBLE_QUOTE)
		heredoc_expansion(token);
	file = open(token->str, O_RDONLY);
	if (file == -1)
	{
		open_file_error(token->str);
		return ;
	}
	tmp = dup(STDIN_FILENO);
	dup2(file, STDIN_FILENO);
	close(file);
	execution(node->left);
	dup2(tmp, STDIN_FILENO);
	close (tmp);
	if (node->type == HEREDOC)
		unlink(token->str);
}

void	handle_redirs(t_ast *node)
{
	t_token			*token;
	int				file;
	const int		tmp = dup(STDOUT_FILENO);

	file = 0;
	token = node->right->exec->first->content;
	if (node->type == L_REDIR || node->type == HEREDOC)
		input_redir(node);
	else if (node->type == R_REDIR)
		file = append_trunc(node, TRUN);
	else if (node->type == APPEND)
		file = append_trunc(node, APEN);
	if (file == -1)
		open_file_error(token->str);
	else if (node->type == R_REDIR || node->type == APPEND)
	{
		if (node->type_prev == 0)
			dup2(file, STDOUT_FILENO);
		close(file);
		execution(node->left);
		dup2(tmp, STDOUT_FILENO);
	}
	close (tmp);
}
