/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:17:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/20 22:09:44 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**splited_args(t_list *tokens);
char	*validate_path(char *exec_name);
void	execute(char **tokens);

t_element	*search_and_or(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (token->type == AND || token->type == OR)
			return (el);
		el = el->prev;
	}
	return (NULL);
}

t_element	*search_pipe(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (token->type == PIPE)
			return (el);
		el = el->prev;
	}
	return (NULL);
}

t_element	*search_redirects(t_list *tokens)
{
	t_token		*token;
	t_element	*el;

	el = tokens->last;
	while (el)
	{
		token = el->content;
		if (token->type == L_REDIR || token->type == R_REDIR
			|| token->type == HEREDOC || token->type == APPEND)
			return (el);
		el = el->prev;
	}
	return (NULL);
}

static void	try_split_else_exec(t_ast *ast_node, t_list *tokens)
{
	if (!ast_node || !tokens)
		return ;
	if (ast_split_node(ast_node, tokens, search_and_or(tokens)))
		return ;
	if (ast_split_node(ast_node, tokens, search_pipe(tokens)))
		return ;
	if (ast_split_node(ast_node, tokens, search_redirects(tokens)))
		return ;
	ast_node->type = EXEC;
	ast_node->exec = tokens;
}

t_ast	*ast_constructor(t_list *tokens)
{
	t_ast		*root;

	root = ft_calloc(1, sizeof(t_ast));
	if (!root)
		return (NULL); //panic tree
	try_split_else_exec(root, tokens);
	return (root);
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

char	**splited_args(t_list *tokens)
{
	char	**splited;
	size_t		index;
	t_element	*el;
	t_token		*token;

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
	execve(path, tokens, __environ);
	// printf("%s\n", path);
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
