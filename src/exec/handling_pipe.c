/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:30:51 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/31 22:11:49 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	close_and_wait(int *fildes, pid_t *f1, pid_t *f2, const int *fds)
{
	int	status;

	close(fildes[0]);
	close(fildes[1]);
	waitpid(*f1, NULL, 0);
	waitpid(*f2, &status, 0);
	dup2(fds[0], fildes[0]);
	dup2(fds[1], fildes[1]);
	close(fds[0]);
	close(fds[1]);
	clear_tree(ast_holder(NULL));
	return (status);
}

static void	dup_and_close(int *fildes)
{
	dup2(fildes[0], STDIN_FILENO);
	dup2(fildes[1], STDOUT_FILENO);
	close(fildes[0]);
	close(fildes[1]);
}

int	handle_pipe(t_ast *node_pipe)
{
	int		fildes[2];
	pid_t	fs[2];
	const int	tmp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	if (pipe(fildes) < 0)
		panic_ast(1, "file descriptor error");
	dup_and_close(fildes);
	execution(node_pipe->left);
	execution(node_pipe->right);
	wait(NULL);
	exit(close_and_wait(fildes, &fs[0], &fs[1], tmp));
}
