/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:13:34 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/27 17:00:45 by bmoretti         ###   ########.fr       */
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

void	execute(char **tokens)
{
	char	*path;

	path = validate_path(tokens[0]);
	if (execve(path, tokens, __environ) < 0)
	{
		tokens = ft_clear_split(tokens);
		if (errno == EACCES)
			panic_ast(126, "minishell: Permission denied");
		else if (errno == ENOENT)
			panic_ast(127, "minishell: Command not found");
		else
			exit(!!errno);
	}
}

char	*validate_path(char *exec_name)
{
	char	**paths;
	char	*cmd;
	int		i;

	paths = ft_split(getenv("PATH"), ':');
	if (access(exec_name, X_OK) == 0)
	{
		cmd = ft_strdup(exec_name);
		return (cmd);
	}
	i = 0;
	while (paths[i])
	{
		cmd = ft_strmerge(ft_strjoin(paths[i], "/"), ft_strdup(exec_name));
		if (access(cmd, X_OK) == 0)
		{
			ft_clear_split(paths);
			return (cmd);
		}
		free(cmd);
		cmd = NULL;
		i++;
	}
	ft_clear_split(paths);
	return (exec_name);
}

void	execution(t_ast *root)
{
	if (!root)
		panic_ast(1, "error creating the AST");
	if (root->type == PIPE)
		handle_pipe(root);
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
