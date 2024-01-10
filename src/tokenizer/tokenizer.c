/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 07:27:10 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/10 14:20:05 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_branch *tokenizer(char *line)
{
	t_branch		*root;
	char			*end;

	root = ft_calloc(1, sizeof(t_branch));
	end = line + ft_strlen(line);
	while (--end > line)
	{
		if (*end == ';')
		{
			root->str = ft_strdup(";");
			*end = '\0';
			root->right = ft_calloc(1, sizeof(t_branch));
			root->right->str = ft_strdup(end + 1);
			root->left = tokenizer(line);
			return (root);
		}
	}
	root->str = line;
	return (root);
}

void	print_tree(t_branch *root)
{
	if (root)
	{
		if (root->left)
			print_tree(root->left);
		ft_putstr_fd(root->str, 1);
		ft_putstr_fd("\n", 1);
		if (root->right)
			print_tree(root->right);
	}
}

void	free_tree(t_branch *root)
{
	if (root)
	{
		if (root->left)
			free_tree(root->left);
		if (root->right)
			free_tree(root->right);
		free(root->str);
		free(root);
		root = NULL;
	}
}
