/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:13:34 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/31 19:49:35 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**splited_args(t_list *tokens)
{
	size_t		index;
	t_element	*el;
	t_token		*token;
	char		**splited;

	el = tokens->first;
	splited = ft_calloc(tokens->size + 1, sizeof(char *));
	if (!splited)
		panic_ast(1, "malloc error");
	index = 0;
	while (el)
	{
		token = el->content;
		splited[index] = ft_strdup(token->str);
		if (!splited[index++])
		{
			ft_clear_split(splited);
			panic_ast(1, "malloc error");
		}
		el = el->next;
	}
	return (splited);
}

void	fork_and_execve(char **tokens, char *path)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		panic_ast(1, "fork error");
	if (!pid && execve(path, tokens, __environ) < 0)
	{
		if (errno == EACCES)
		{
			if ((open(path, O_DIRECTORY | O_RDONLY)) != -1)
				panic_ast(126, "minishell: Is a directory");
			else
				panic_ast(126, "minishell: Permission denied");
		}
		else if (errno == ENOENT)
			panic_ast(127, "minishell: Command not found");
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

	if (builtins_caller(tokens) == -1)
	{
		path = validate_path(tokens[0]);
		fork_and_execve(tokens, path);
		free(path);
	}
	ft_clear_list(&tokens);
}

char	*validate_path(char *exec_name)
{
	char	**paths;
	char	*cmd;
	int		i;

	paths = ft_split(ft_getenv("PATH"), ':');
	if (access(exec_name, X_OK) == 0)
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
	else if (root->type == R_REDIR || root->type == L_REDIR)
		handle_redirs(root);
	else if (root->type == APPEND)
		handle_redirs(root);
	else if (root->left)
		execution(root->left);
	else if (root->right)
		execution(root->right);
	else if (root->exec)
	{
		expansions(root->exec);
		execute(splited_args(root->exec));
	}
}
