/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_plus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 01:51:52 by nivicius          #+#    #+#             */
/*   Updated: 2024/02/15 02:02:32 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_infile(t_ast *node, t_token *token, int *file)
{
		set_fd_in(node);
		if (input_redir(node))
		{
			if (node->set_fd)
			{
				node->first_infile_err = 1;
				set_next_node_err(node);
				open_file_error(token->str);
			}
			*file = -1;
		}
}

void	handle_outfile(t_ast *node, int *file)
{
	set_fd_out(node);
	temp_fd(node);
	if (node->type == R_REDIR)
		*file = append_trunc(node, TRUN);
	else if (node->type == APPEND)
		*file = append_trunc(node, APEN);

}
