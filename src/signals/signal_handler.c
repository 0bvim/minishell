/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:15:21 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/20 09:31:26 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigint_handler(int signal)
{
	g_last_signal = signal;
	if (is_fork(-1))
	{
		environ_holder(NULL, 1);
		static_pwd(NULL, 1);
		static_old_pwd(NULL, 1);
		close(STDIN_FILENO);
		close(STDOUT_FILENO);
		close(STDERR_FILENO);
	}
	ast_holder(NULL, 1);
	token_list_holder(NULL, 1, 0);
	if (on_heredoc(-1))
		close(STDIN_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	ft_putstr_fd("\n", 1);
	if (!is_after_prompt(-1))
		rl_redisplay();
	last_exit_status(130);
}
