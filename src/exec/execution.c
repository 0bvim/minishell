/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:13:34 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/24 17:25:47 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	handle_pipe(t_ast *node_pipe);

char	**splited_args(t_list *tokens)
{
	size_t		index;
	t_element	*el;
	t_token		*token;
	char		**splited;

	el = tokens->first;
	splited = ft_calloc(tokens->size + 1, sizeof(char *));
	if (!splited)
		return (NULL); //panic tree
	index = 0;
	while (el)
	{
		token = el->content;
		splited[index++] = token->str;
		el = el->next;
	}
	return (splited);
}

void	execute(char **tokens)
{
	char	*path;

	path = validate_path(tokens[0]);
	if (!path)
	{
		ft_clear_split(tokens);
		exit(EXIT_FAILURE);
	}
	if (execve(path, tokens, __environ) < 0)
	{
		ft_clear_split(tokens);
		free(path);
		exit(EXIT_FAILURE);
	}
}

char	*validate_path(char *exec_name)
{
	char	**paths;
	char	*cmd;
	int		i;

	paths = ft_split(getenv("PATH"), ':');
	if (access(exec_name, F_OK | X_OK) == 0)
	{
		cmd = ft_strdup(exec_name);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		cmd = ft_strmerge(ft_strjoin(paths[i], "/"), ft_strdup(exec_name));
		if (access(cmd, F_OK | X_OK) == 0)
		{
			ft_clear_split(paths);
			return (cmd);
		}
		free(cmd);
		cmd = NULL;
		i++;
	}
	ft_clear_split(paths);
	return (NULL);
}

void	execution(t_ast *root)
{
	// pid_t	leaf;

	if (!root)
		return ; //panic
	if (root->type == PIPE)
		handle_pipe(root);
	else if (root->left)
		execution(root->left);
	else if (root->right)
		execution(root->right);
	else if (root->exec)
	{
		expansions(root->exec);
		// leaf = fork();
		// if (!leaf)
		execute(splited_args(root->exec));
	}
}

int	handle_pipe(t_ast *node_pipe)
{
	pid_t	fildes[2];
	pid_t	f1;
	pid_t	f2;
	pid_t	status;

	if (pipe(fildes) < 0)
		exit(1); //panic opening pipe
	f1 = fork();
	if (f1 < 0)
		exit(1); //panic opening fork
	if (f1 == 0)
	{
		dup2(fildes[1], 1);
		close(fildes[0]);
		close(fildes[1]);
		execution(node_pipe->left);
	}
	f2 = fork();
	if (f2 < 0)
		exit(1); //panic opening fork
	if (f2 == 0)
	{
		dup2(fildes[0], 0);
		close(fildes[0]);
		close(fildes[1]);
		execution(node_pipe->right);
	}
	close(fildes[0]);
	close(fildes[1]);
	waitpid(f1, NULL, 0);
	waitpid(f2, &status, 0);
	return (status);
}
