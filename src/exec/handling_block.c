/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_block.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 10:39:19 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/18 22:55:36 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

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
		is_fork(1);
		str = block->str;
		block->str = NULL;
		ast_holder(NULL, 1);
		parser(str);
		clear_everything();
		exit(last_exit_status(-1));
	}
	pid_last_exit_status(pid);
}
