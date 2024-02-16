/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:17:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/15 10:57:13 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	try_split_else_exec(t_ast *ast_node, t_list *tokens)
{
	if (ast_split_node(ast_node, tokens, search_and_or(tokens)))
		return ;
	if (ast_split_node(ast_node, tokens, search_pipe(tokens)))
		return ;
	if (ast_split_node(ast_node, tokens, search_redir(tokens)))
		return ;
	ast_node->type = EXEC;
	ast_node->exec = tokens;
}

t_ast	*ast_constructor(t_list *tokens)
{
	t_ast		*root;

	root = ft_calloc(1, sizeof(t_ast));
	if (!root)
	{
		panic_tokenizer(1, "fail to create the root node of AST");
		return (NULL);
	}
	try_split_else_exec(root, tokens);
	return (root);
}
