/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:39:19 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/16 13:54:01 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

// void	handle_block(t_token *block)
// {
// 	int		to_child[2];
// 	int		from_child[2];
// 	pid_t	pid;
// 	char	*args[2] = {"./minishell", NULL};
// 	int		bkp[2] = {dup(STDIN_FILENO), dup(STDOUT_FILENO)};

// 	pipe(to_child);
// 	pipe(from_child);
// 	pid = fork();
// 	if (pid > 0)
// 	{
// 		close(to_child[0]);
// 		close(from_child[1]);
// 		write(to_child[1], block->str, strlen(block->str) + 1);
// 		dup2(from_child[0], bkp[1]);
// 		wait(NULL);	
// 	}
// 	if (!pid)
// 	{
// 		close(to_child[1]);
// 		close(from_child[0]);
// 		dup2(to_child[0], STDIN_FILENO);
// 		dup2(from_child[1], STDOUT_FILENO);
// 		close(STDIN_FILENO);
// 		close(STDOUT_FILENO);
// 		execve("./minishell", args, environ_holder(NULL, 0));
// 		ft_putstr_fd("deu ruim", STDERR_FILENO);
// 	}
// 	close(to_child[1]);
// 	close(from_child[0]);
// 	dup2(bkp[0], STDIN_FILENO);
// 	dup2(bkp[1], STDOUT_FILENO);
// }

void	handle_block(t_token *block)
{
	pid_t	pid;
	char	*str;

	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("fork error", 2);
		last_exit_status(1);
		return ;
	}
	if (!pid)
	{
		str = block->str;
		block->str = NULL;
		ast_holder(NULL, 1);
		parser(str);
		clear_everything();
		exit(last_exit_status(-1));
	}
	pid_last_exit_status(pid);
}
