/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:30:51 by vde-frei          #+#    #+#             */
/*   Updated: 2024/04/19 09:26:54 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	fork_process(int *fildes, t_ast *node_pipe, int left_right)
{
	is_fork(1);
	if (!left_right)
		dup2(fildes[1], STDOUT_FILENO);
	else if (left_right == 1)
		dup2(fildes[0], STDIN_FILENO);
	close(fildes[0]);
	close(fildes[1]);
	if (!left_right)
	{
		execution(node_pipe->left);
		close_fds();
	}
	else if (left_right == 1)
	{
		execution(node_pipe->right);
		close_fds();
	}
	ast_holder(NULL, 1);
	environ_holder(NULL, 1);
	static_pwd(NULL, 1);
	static_old_pwd(NULL, 1);
	exit(last_exit_status(-1));
}

static void	wait_restore_fds(int *fildes, int *forks)
{
	close(fildes[0]);
	close(fildes[1]);
	pid_last_exit_status(forks[0]);
	pid_last_exit_status(forks[1]);
}

int	handle_pipe(t_ast *node_pipe)
{
	int			fildes[2];
	pid_t		fs[2];

	if (!pipe(fildes))
	{
		fs[0] = fork();
		if (fs[0] < 0)
			ft_putstr_fd("fork error\n", STDERR_FILENO);
		if (fs[0] == 0)
			fork_process(fildes, node_pipe, 0);
		fs[1] = fork();
		if (fs[1] < 0)
			ft_putstr_fd("fork error\n", STDERR_FILENO);
		if (fs[1] == 0)
			fork_process(fildes, node_pipe, 1);
		wait_restore_fds(fildes, fs);
	}
	else
		last_exit_status(EXIT_FAILURE);
	close(fildes[0]);
	close(fildes[1]);
	return (last_exit_status(-1));
}
