/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 22:30:51 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/25 14:59:32 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	close_and_wait(int *fildes, pid_t *f1, pid_t *f2)
{
	int status;

	close(fildes[0]);
	close(fildes[1]);
	waitpid(*f1, NULL, 0);
	waitpid(*f2, &status, 0);
	return (status);
}

static void	dup_and_close(int *fildes, int fd_to_dup)
{
	dup2(fildes[fd_to_dup], fd_to_dup);
	close(fildes[0]);
	close(fildes[1]);
}

int	handle_pipe(t_ast *node_pipe)
{
	int		fildes[2];
	pid_t	f1;
	pid_t	f2;

	if (pipe(fildes) < 0)
		exit(1); //panic opening pipe
	f1 = fork();
	if (f1 < 0)
		exit(1); //panic opening fork
	if (f1 == 0)
	{
		dup_and_close(fildes, STDOUT_FILENO);
		execution(node_pipe->left);
	}
	f2 = fork();
	if (f2 < 0)
		exit(1); //panic opening fork
	if (f2 == 0)
	{
		dup_and_close(fildes, STDIN_FILENO);
		execution(node_pipe->right);
	}
	exit(close_and_wait(fildes, &f1, &f2));
}
