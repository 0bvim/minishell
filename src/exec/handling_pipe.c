/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:30:51 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/01 01:31:34 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void fork_process(int *fildes, t_ast *node_pipe,
	const int *tmp, int left_right)
{
	if (left_right == 0)
		dup2(fildes[1], STDOUT_FILENO);
	else
		dup2(fildes[0], STDIN_FILENO);
	close(fildes[0]);
	close(fildes[1]);
	close(tmp[0]);
	close(tmp[1]);
	if (left_right == 0)
		execution(node_pipe->left);
	else
		execution(node_pipe->right);
	clear_tree(ast_holder(NULL));
	environ_holder(NULL, 1);
	exit(last_exit_status(-1));
}

static void	wait_restore_fds(int *fildes, const int *tmp, int *forks)
{
	close(fildes[0]);
	close(fildes[1]);
	pid_last_exit_status(forks[0]);
	pid_last_exit_status(forks[1]);
	dup2(tmp[0], STDIN_FILENO);
	dup2(tmp[1], STDOUT_FILENO);
}

int	handle_pipe(t_ast *node_pipe)
{
	int		fildes[2];
	pid_t	fs[2];
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	if (!pipe(fildes))
	{
		fs[0] = fork();
		if (fs[0] < 0)
			ft_putstr_fd("fork error\n", STDERR_FILENO);
		if (fs[0] == 0)
			fork_process(fildes, node_pipe, tmp, 0);
		fs[1] = fork();
		if (fs[1] < 0)
			ft_putstr_fd("fork error\n", STDERR_FILENO);
		if (fs[1] == 0)
			fork_process(fildes, node_pipe, tmp, 1);
		wait_restore_fds(fildes, tmp, fs);
	}
	else
		last_exit_status(EXIT_FAILURE);
	close(tmp[0]);
	close(tmp[1]);
	return (last_exit_status(-1));
}
