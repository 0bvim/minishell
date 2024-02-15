/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_fd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:17:19 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/15 01:36:05 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_fd_out(t_ast *node)
{
	static int	have_prev;

	if (have_prev || node->outfile_set)
		return ;
	if (is_redirect(node->type) && !is_redirect_out(node->type_prev))
	{
		have_prev = 0;
		node->set_fd = 1;
		set_next_node(node);
	}
}

void	set_fd_in(t_ast *node)
{
	static int	have_prev;

	if (have_prev || node->infile_set)
		return ;
	if (is_redirect(node->type) && !is_redirect_in(node->type_prev))
	{
		have_prev = 0;
		node->set_fd = 1;
		set_next_node(node);
	}
}

void	temp_fd(t_ast *node)
{
	int		fd;
	t_token	*tk;
	char	*str;

	if (!node->set_fd)
		return ;
	tk = node->right->exec->first->content;
	if (ft_strrchr(tk->str, '/'))
		str = (ft_strdup(ft_strrchr(tk->str, '/') + 1));
	else	
		str = ft_strdup(tk->str);
	node->tmp_file = ft_strmerge(ft_strdup("/tmp/_"), str);
	fd = open(node->tmp_file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	node->fd = fd;
	dup2(fd, STDOUT_FILENO);
	close (fd);
}
