/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/05 18:45:05 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
void	get_fd_content(pid_t *fd, int flag, char *file_name);

// static int	append_trunc(t_ast *node, int flag)
// {
// 	t_token	*token;
// 	t_list	*right_tokens;

// 	node->left->type_prev = node->type;
// 	token = node->right->exec->first->content;
// 	right_tokens = node->right->exec;
// 	substitute_first_token_str(right_tokens);
// 	return (open(token->str, flag, 0644));
// }

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
	t_list	*right_tokens;
	t_token	*token;
	int		file;
	int		tmp;

	right_tokens = node->right->exec;
	substitute_first_token_str(right_tokens);
	token = right_tokens->first->content;
	if (node->type == HEREDOC && token->type != QUOTE
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
	close(tmp);
	if (node->type == HEREDOC)
		unlink(token->str);
}

void	infile_redirs(t_ast *node)
{
	t_token		*token;

	token = node->right->exec->first->content;
	if (node->type == L_REDIR || node->type == HEREDOC)
		input_redir(node);
}

void	handle_redirs(t_ast *node)
{
	t_token		*token;
	int			file;
	pid_t		fd[2];
	const int	tmp = dup(STDOUT_FILENO);

	file = 0;
	if (pipe(fd) == -1)
	{
		close (tmp);
		ft_putstr_fd("pipe error", 2);
		return ;
	}
	dup2(fd[1], STDOUT_FILENO);
	token = node->right->exec->first->content;
	execution(node->left);
	close (fd[1]);
	close (fd[0]);
	if (!last_exit_status(-1))
	{
		substitute_first_token_str(node->right->exec);
		if (node->type == R_REDIR)
			get_fd_content(fd, TRUN, token->str);
		else if (node->type == APPEND)
			get_fd_content(fd, APEN, token->str);
	}
	dup2(tmp, STDOUT_FILENO);
	close(tmp);
}

void	get_fd_content(pid_t *fd, int flag, char *file_name)
{
	char	*text;
	char	*str;
	int		file;

	file = open(file_name, flag, 0644);
	if (file == -1)
		open_file_error(file_name);
	text = ft_calloc(1, 1);
	str = get_next_line(fd[0]);
	while (str)
	{
		text = ft_strmerge(text, str);
		str = get_next_line(fd[0]);
	}
	write(file, text, ft_strlen(text));
	close (fd[0]);
	free(text);
	close(file);
}
