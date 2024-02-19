/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:13:34 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/19 01:18:34 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		search_command(char *exec_name);
void	treat_errors(char *path);

static void	fork_and_execve(char **tokens, char *path)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		panic_ast(1, "fork error");
	if (!pid)
	{
		is_fork(1);
		signal(SIGQUIT, SIG_DFL);
		if (execve(path, tokens, environ_holder(NULL, 0)) < 0)
		{
			treat_errors(path);
			ft_clear_list(&tokens);
			free(path);
			exit(last_exit_status(-1));
		}
	}
	pid_last_exit_status(pid);
}

static char	*validate_path(char *exec_name)
{
	char	**paths;
	char	*cmd;
	int		i;

	paths = ft_split(ft_getenv("PATH"), ':');
	if (access(exec_name, F_OK) == 0 || !paths)
	{
		ft_clear_list(&paths);
		return (ft_strdup(exec_name));
	}
	i = 0;
	while (paths[i])
	{
		cmd = ft_strmerge(ft_strjoin(paths[i], "/"), ft_strdup(exec_name));
		if (access(cmd, F_OK) == 0)
		{
			ft_clear_list(&paths);
			return (cmd);
		}
		free(cmd);
		cmd = NULL;
		i++;
	}
	ft_clear_list(&paths);
	return (ft_strdup(exec_name));
}

static void	execute(char **tokens)
{
	char	*path;

	if (!tokens || !tokens[0])
		return ;
	g_last_signal = 0;
	if (builtins_caller(tokens) == -1)
	{
		path = validate_path(tokens[0]);
		fork_and_execve(tokens, path);
		free(path);
	}
	if (g_last_signal == SIGINT)
		last_exit_status(130);
	ft_clear_list(&tokens);
}

void	execution(t_ast *root)
{
	if (root->type == AND || root->type == OR)
		handle_and_or(root);
	else if (root->type == PIPE)
		handle_pipe(root);
	else if (is_redirect(root->type))
		handle_redirs(root);
	else if (root->left)
		execution(root->left);
	else if (root->right)
		execution(root->right);
	else if (root->exec && root->exec->first)
	{
		if (((t_token *)root->exec->first->content)->type == BLOCK)
			handle_block(((t_token *)root->exec->first->content));
		else
			execute(tokens_to_args(root->exec));
	}
}
