/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_inf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 02:43:22 by nivicius          #+#    #+#             */
/*   Updated: 2024/02/17 01:34:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// int	file_err(t_ast *node, t_token *tk, const int *tmp)
// {
// 	node->error = 1;
// 	if (is_redirect_out(node->type))
// 		outfile_error(node, tk);
// 	if (is_redirect_in(node->type) && check_infile(node))
// 	{
// 		if (!is_redirect(node->left->type))
// 		{
// 			close_tmp(tmp);
// 			return (1);
// 		}
// 		node->fake_file = open("/tmp/dopel_file", TRUN, 0644);
// 		dup2(node->fake_file, STDIN_FILENO);
// 	}
// 	else if (node->left->first_infile_err)
// 	{
// 		close(node->fd);
// 		dup2(tmp[0], STDIN_FILENO);
// 		close_tmp(tmp);
// 		return (1);
// 	}
// 	return (0);
// }
//
// void	infile_after(t_ast *node, const int *tmp)
// {
// 	if (node->fake_file)
// 	{
// 		last_exit_status(1);
// 		close(node->fake_file);
// 	}
// 	dup2(tmp[0], STDIN_FILENO);
// }
//
// void	init_redirs(t_ast *node, t_token **tk, int *file)
// {
// 	*file = 0;
// 	node->left->type_prev = node->type;
// 	*tk = node->right->exec->first->content;
// }
//
// void	seek_and_destroy(t_ast *node, int *file, const int *tmp)
// {
// 	if (is_redirect_out(node->type))
// 		after_ex(node, file, tmp);
// 	if (is_redirect_in(node->type))
// 		infile_after(node, tmp);
// }
