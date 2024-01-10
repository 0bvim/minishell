/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:27:10 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/10 19:36:40 by bmoretti         ###   ########.fr       */
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
	if (!ft_strncmp(str, "$(", 2))
		return (EVAL);
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

void	define_branch_type(char **line, char **end, t_branch *branch)
{
	if ((*end - 1) >= *line && *(*end - 1) == **end)
	{
		branch->type = which_token_double(*end - 1);
		*(*end - 1) = '\0';
	}
	else
		branch->type = which_token(*end);
	**end = '\0';
}

void	block_handler(char **line, char **end, t_branch *branch)
{
	int	i;

	i = 1;
	while (--*end >= *line && i)
	{
		if (**end == ')' && i++)
			break;
		else if (**end == '(' && i--)
			break;
	}
	if (!i)
	{
		**end = '\0';
		if (*(end - 1) >= *line && *(*end - 1) == '$')
		{
			*(*end - 1) = '\0';
			branch->type = EVAL;
		}
		else
			branch->type = BLOCK;
		branch->right = tokenizer(*end + 1, branch);
	}
	else
		free_tree(branch);
}


t_branch *tokenizer(char *line, t_branch *root)
{
	t_branch		*branch;
	char			*end;

	branch = new_branch(root);
	end = line + ft_strlen(line);
	while (--end >= line)
	{
		if (ft_issymbol(*end))
		{
			define_branch_type(&line, &end, branch);
			if (branch->type == R_PAREN)
				block_handler(&line, &end, branch);
			else
			{
				branch->right = new_branch(branch);
				branch->right->type = EXEC;
				branch->right->str = ft_strdup(end + 1);
			}
			branch->left = tokenizer(line, branch);
			return (branch);
		}
	}
	branch->type = EXEC;
	branch->str = line;
	return (branch);
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
