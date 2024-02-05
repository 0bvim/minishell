/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_redirs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:26:07 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/05 10:45:47 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	input_redir(t_ast *node_pipe);
static int	append_trunc(t_ast *node_pipe, t_token *token, int flag);
static void	open_file_error(char *file_name);

void	handle_redirs(t_ast *node_pipe)
{
	t_token			*token;
	int				file;
	const int		tmp = dup(STDOUT_FILENO);

	file = 0;
	token = node_pipe->right->exec->first->content;
	if (node_pipe->type == L_REDIR || node_pipe->type == HEREDOC)
		input_redir(node_pipe);
	else if (node_pipe->type == R_REDIR)
		file = append_trunc(node_pipe, token, TRUN);
	else if (node_pipe->type == APPEND)
		file = append_trunc(node_pipe, token, APEN);
	if (file == -1)
		open_file_error(token->str);
	else if (node_pipe->type == R_REDIR || node_pipe->type == APPEND)
	{
		if (node_pipe->type_prev == 0)
			dup2(file, STDOUT_FILENO);
		close(file);
		execution(node_pipe->left);
		dup2(tmp, STDOUT_FILENO);
	}
	close (tmp);
}

static void	input_redir(t_ast *node_pipe)
{
	t_token		*token;
	int			file;
	int			tmp;

	token = node_pipe->right->exec->first->content;
	if (node_pipe->type == HEREDOC && token->type != QUOTE \
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
	execution(node_pipe->left);
	dup2(tmp, STDIN_FILENO);
	close (tmp);
	if (node_pipe->type == HEREDOC)
		unlink(token->str);
}

static int	append_trunc(t_ast *node_pipe, t_token *token, int flag)
{
	char	**tokens;
	int		i;
	char	*path;
	t_token	*token1;

	(void)token;
	token1 = node_pipe->right->exec->first->content;
	node_pipe->left->type_prev = node_pipe->type;
	tokens = tokens_to_args(node_pipe->right->exec);
	path = ft_calloc(1, sizeof(char));
	i = -1;
	while (tokens[++i])
		path = ft_strmerge(path, tokens[i]);
	free (tokens);
	free (token1->str);
	token1->str = path;
	return (open(token1->str, flag, 0644));
}

static void	open_file_error(char *file_name)
{
	if (!access(file_name, F_OK))
		ft_putstr_fd("minishell: Permission denied\n", 2);
	else
		ft_putstr_fd("minishell: No such file or directory\n", 2);
	last_exit_status(1);
}
