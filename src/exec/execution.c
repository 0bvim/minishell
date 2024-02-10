/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:13:34 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/09 23:31:35 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	fork_and_execve(char **tokens, char *path)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		panic_ast(1, "fork error");
	if (!pid && execve(path, tokens, environ_holder(NULL, 0)) < 0)
	{
		if (errno == EACCES)
		{
			if ((open(path, O_DIRECTORY | O_RDONLY)) != -1)
				panic_ast(126, "minishell: Is a directory");
			else
				panic_ast(126, "minishell: Permission denied");
		}
		else if (errno == ENOENT)
			panic_ast(127, "minishell: command not found");
		else
			panic_ast(!!errno, NULL);
		ft_clear_list(&tokens);
		free(path);
		exit(last_exit_status(-1));
	}
	pid_last_exit_status(pid);
}

void	execute(char **tokens)
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

char	*validate_path(char *exec_name)
{
	char	**paths;
	char	*cmd;
	int		i;

	paths = ft_split(ft_getenv("PATH"), ':');
	if (access(exec_name, X_OK) == 0 || !paths)
	{
		ft_clear_list(&paths);
		return (ft_strdup(exec_name));
	}
	i = 0;
	while (paths[i])
	{
		cmd = ft_strmerge(ft_strjoin(paths[i], "/"), ft_strdup(exec_name));
		if (access(cmd, X_OK) == 0)
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

void	execution(t_ast *root)
{
	if (root->type == PIPE)
		handle_pipe(root);
	else if (is_redirect(root->type))
		handle_redirs(root);
	else if (root->left)
		execution(root->left);
	else if (root->right)
		execution(root->right);
	else if (root->exec && root->exec->first)
		execute(tokens_to_args(root->exec));
}
