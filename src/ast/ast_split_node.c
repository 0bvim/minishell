/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_split_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:16:44 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/17 13:43:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ast_split_node(t_ast *ast_node, t_list *tokens,
	t_element *el_to_split)
{
	t_list	*right;

	if (!ast_node || !tokens || !el_to_split)
		return ;
	right = ft_lstsplit(tokens, el_to_split);
	if (!right)
		return ; //panic tree
	ast_node->type = ((t_token *)tokens->last->content)->type;
	ft_lstdelone(tokens, tokens->last, free_token);
	ast_node->left = ast_constructor(tokens);
	ast_node->right = ast_constructor(right);
}
