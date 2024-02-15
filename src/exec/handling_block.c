/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:39:19 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/15 18:34:11 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_block(t_token *block)
{
	int		pipe1[2];
	int		pipe2[2];
	pid_t	pid;
	char	*args[2] = {"minishell", NULL};
	int		dups[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

	pipe(pipe1);
	pipe(pipe2);
	pid = fork();
	if (!pid)
	{
		close(pipe1[0]);
		close(pipe2[1]);
		dup2(pipe1[0], STDIN_FILENO);
		dup2(pipe2[1], STDOUT_FILENO);
		close(pipe1[1]);
		close(pipe2[0]);
		execve("./minishell", args, environ_holder(NULL, 0));
	}
	close(pipe1[1]);
	close(pipe2[0]);
	dup2(pipe1[1], STDOUT_FILENO);
	write(pipe1[1], block->str, ft_strlen(block->str));
	close(pipe1[1]);
	wait(NULL);
	dup2(dups[0], STDIN_FILENO);
	dup2(dups[1], STDOUT_FILENO);
	close(pipe2[1]);
}

// void	handle_block(t_token *node_block)
// {
// 	pid_t	pid;
// 	char	*args[2] = {"minishell", NULL};

// 	pid = fork();
// 	if (!pid)
// 	{
// 		int	file = open("/tmp/test", O_CREAT, O_RDWR, O_TRUNC, 0644);
// 		ft_putendl_fd(node_block->str, file);
// 		dup2(file, 0);
// 		close(file);
// 		execve("./minishell", args, environ_holder(NULL, 0));
// 	}
// }