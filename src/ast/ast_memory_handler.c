/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_memory_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:31:01 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/02 11:46:43 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

t_ast	*ast_holder(t_ast *root, int to_free)
{
	static t_ast	*ast_address;

	if (root)
		ast_address = root;
	if (ast_address && to_free)
	{
		clear_tree(ast_address);
		ast_address = NULL;
	}
	return (ast_address);
}

void	panic_ast(int error, char *msg)
{
	ft_putendl_fd(msg, 2);
	ast_holder(NULL, 1);
	environ_holder(NULL, 1);
	last_exit_status(error);
}
