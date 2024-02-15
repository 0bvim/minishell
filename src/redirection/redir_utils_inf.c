/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_inf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 02:43:22 by nivicius          #+#    #+#             */
/*   Updated: 2024/02/15 02:48:39 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	file_err(t_ast *node, t_token *tk, const int *tmp)
{
	node->error = 1;
	if (is_redirect_out(node->type))
		outfile_error(node, tk);
	if (is_redirect_in(node->type) && check_infile(node))
	{
		if (!is_redirect(node->left->type))
		{
			close_tmp(tmp);
			return(1);
		}
		node->fake_file = open("/tmp/dopel_file", TRUN, 0644);
		dup2(node->fake_file, STDIN_FILENO);
	}
	else if (node->left->first_infile_err)
	{
		close(node->fd);
		dup2(tmp[0], STDIN_FILENO);
		close_tmp(tmp);
		return (1);
	}
	return (0);
}
