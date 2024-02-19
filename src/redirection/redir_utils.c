/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 23:37:33 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/19 02:14:42 by nivicius         ###   ########.fr       */
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

void	dup_close_tmp(const int *tmp)
{
	dup2(tmp[1], STDOUT_FILENO);
	dup2(tmp[0], STDIN_FILENO);
	close(tmp[0]);
	close(tmp[1]);
}

int	expand_redirs(t_list *right_tokens)
{
	char	**args;
	t_token	*token;
	size_t	list_size;

	list_size = right_tokens->size;
	args = tokens_to_args(right_tokens);
	token = right_tokens->first->content;
	free(token->str);
	token->str = ft_strdup(args[0]);
	if (!token->str)
		return (0);
	ft_clear_list(&args);
	if (right_tokens->size > list_size)
	{
		ft_putendl_fd("ambiguous redirect", 2);
		last_exit_status(1);
		return (0);
	}
	return (1);
}

void	fd_keeper(const int *tmp, int node_fd, int to_close)
{
	static int	open_fd[3];

	if (!to_close)
	{
		open_fd[0] = tmp[0];
		open_fd[1] = tmp[1];
		open_fd[2] = node_fd;
	}
	else
	{
		close(open_fd[0]);
		close(open_fd[1]);
		close(open_fd[2]);
	}
}
