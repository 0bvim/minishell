/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_memory_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:31:01 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/26 12:56:51 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_ast	*ast_holder(t_ast *root)
{
	static t_ast	*ast_address;

	if (root)
		ast_address = root;
	return (ast_address);
}

void	clear_tree(t_ast *root)
{
	if (!root)
		return ;
	if (root->left)
	{
		clear_tree(root->left);
		root->left = NULL;
	}
	if (root->right)
	{
		clear_tree(root->right);
		root->right = NULL;
	}
	if (root->exec)
	{
		ft_lstclear(root->exec, free_token);
		root->exec = NULL;
	}
	free(root);
}

void	panic_ast(int error, char *msg)
{
	ft_putendl_fd(msg, 2);
	if (ast_holder(NULL))
		clear_tree(ast_holder(NULL));
	exit(error);
}
