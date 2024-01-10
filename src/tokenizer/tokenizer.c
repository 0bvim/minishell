/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:27:10 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/10 16:20:11 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	which_token_double(char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (AND);
	if (!ft_strncmp(str, "||", 2))
		return (OR);
	if (!ft_strncmp(str, "<<", 2))
		return (HEREDOC);
	if (!ft_strncmp(str, ">>", 2))
		return (APPEND);
	return (0);
}

static int	which_token(char *str)
{
	if (which_token_double(str))
		return (which_token_double(str));
	if (!*str)
		return (TOKEN_NULL);
	if (*str == '|')
		return (PIPE);
	if (*str == ';')
		return (SEMICOLON);
	if (*str == '(')
		return (L_PAREN);
	if (*str == ')')
		return (R_PAREN);
	if (*str == '\'')
		return (QUOTE);
	if (*str == '"')
		return (DOUBLE_QUOTE);
	if (*str == '<')
		return (L_REDIR);
	if (*str == '>')
		return (R_REDIR);
	return (ARGUMENT);
}

t_branch	*new_branch(t_branch *parent)
{
	t_branch	*branch;

	branch = ft_calloc(1, sizeof(t_branch));
	if (branch)
	{
		branch->parent = parent;
		return (branch);
	}
	free_tree(parent);
	exit (EXIT_FAILURE);
}

t_branch *tokenizer(char *line)
{
	t_branch		*root;
	char			*end;

	root = new_branch(NULL);
	end = line + ft_strlen(line);
	while (--end >= line)
	{
		if (ft_issymbol(*end))
		{
			if ((end - 1) >= line && *(end - 1) == *end)
			{
				root->type = which_token_double(end - 1);
				*(end - 1) = '\0';
			}
			else
				root->type = which_token(end);
			*end = '\0';
			root->right = new_branch(root);
			root->right->type = EXEC;
			root->right->str = ft_strdup(end + 1);
			root->left = tokenizer(line);
			return (root);
		}
	}
	root->type = EXEC;
	root->str = line;
	return (root);
}

void	print_tree(t_branch *root)
{
	if (root)
	{
		if (root->left)
			print_tree(root->left);
		if (root->type == EXEC)
			printf("command: %s\n", root->str);
		else
			printf("type: %d\n", root->type);
		if (root->right)
			print_tree(root->right);
	}
}

void	free_tree(t_branch *branch)
{
	if (branch)
	{
		if (branch->left)
		{
			branch->left->parent = NULL;
			free_tree(branch->left);
		}
		if (branch->right)
		{
			branch->right->parent = NULL;
			free_tree(branch->right);
		}
		if (branch->parent)
			free_tree(branch->parent);
		if (branch->str)
		{
			free(branch->str);
			branch->str = NULL;
		}
		free(branch);
		branch = NULL;
	}
}
