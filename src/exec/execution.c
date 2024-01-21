/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 03:13:34 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/21 04:35:45 by vde-frei         ###   ########.fr       */
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
	pid_t	leaf;

	if (root->left)
		execution(root->left);
	if (root->right)
		execution(root->right);
	if (root->exec)
	{
		expansions(root->exec);
		leaf = fork();
		if (!leaf)
			execute(splited_args(root->exec));
	}
}
