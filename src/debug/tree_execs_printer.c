/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_execs_printer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:59:27 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/17 11:10:43 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tree_execs_printer(t_ast *root)
{
	t_element	*el;

	if (root->left)
		tree_execs_printer(root->left);
	if (root->right)
		tree_execs_printer(root->right);
	if (root->exec)
	{
		el = root->exec->first;
		while (el)
		{
			printf("%s ", ((t_token *)el->content)->str);
			el = el->next;
		}
		printf("\n");
	}
}