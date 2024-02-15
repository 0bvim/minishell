/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:37:33 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/15 03:18:53 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_redirect_in(int type)
{
	return (type == L_REDIR || type == HEREDOC);
}

int	is_redirect_out(int type)
{
	return (type == R_REDIR || type == APPEND);
}

void	set_next_node(t_ast *node)
{
	t_ast	*tmp;

	tmp = 0;
	if (node->left)
		tmp = node->left;
	while (tmp)
	{
		if (tmp->type == node->type)
		{
			if (is_redirect_in(node->type))
				tmp->infile_set = 1;
			else if (is_redirect_out(node->type))
				tmp->outfile_set = 1;
		}
		tmp = tmp->left;
	}
}

void	set_next_node_err(t_ast *node)
{
	t_ast	*tmp;

	tmp = 0;
	if (node->left)
		tmp = node->left;
	while (tmp)
	{
		if (is_redirect_in(tmp->type))
			tmp->first_infile_err = node->first_infile_err;
		else if (is_redirect_out(tmp->type))
			tmp->first_outfile_err = node->first_outfile_err;
		tmp = tmp->left;
	}
}

int	check_infile(t_ast *node)
{
	t_ast	*tmp;

	tmp = node->left;
	while (tmp)
	{
		if (is_redirect_in(tmp->type))
			return (0);
		tmp = tmp->left;
	}
	return (1);
}
