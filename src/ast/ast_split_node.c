/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_split_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:16:44 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/31 18:01:59 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * This function transfers all elements, except the first one, from the source
 * list to the destination list.
 *
 * It is particularly useful in scenarios such as "echo 42 > is fun", where
 * "42" and "fun" are arguments of "echo" and are being redirected to a file
 * named "is". In the resulting abstract syntax tree (AST), "echo 42 fun"
 * should be on the left node, while "is" should be on the right node of the
 * redirection type node.
 *
 * @param dest The list where elements from the source list will be
 * transferred to.
 * @param src The list from which elements will be transferred. The first
 * element will remain in this list.
 */
static void	transfer_all_elements_keep_first(t_list *dest, t_list *src)
{
	if (!dest || !src)
		return ;
	while (src->size > 1)
		ft_lstadd_back(dest, ft_lstpop(src, 1));
}

int	ast_split_node(t_ast *ast_node, t_list *tokens,
	t_element *el_to_split)
{
	t_list	*right;

	if (!ast_node || !tokens || !el_to_split)
		return (0);
	right = ft_lstsplit(tokens, el_to_split);
	if (!right)
	{
		panic_tokenizer(1, NULL);
		panic_ast(1, "panic while spliting tokens to create AST");
		return (-1);
	}
	ast_node->type = ((t_token *)tokens->last->content)->type;
	ft_lstdelone(tokens, tokens->last, free_token);
	if (ast_node->type == L_REDIR || ast_node->type == R_REDIR
		|| ast_node->type == HEREDOC || ast_node->type == APPEND)
		transfer_all_elements_keep_first(tokens, right);
	ast_node->left = ast_constructor(tokens);
	ast_node->right = ast_constructor(right);
	return (1);
}
