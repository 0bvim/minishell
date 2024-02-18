/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:15:21 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/18 11:22:04 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		//printf("SIGINT handler!\n");
		g_last_signal = SIGINT;
		if (ast_holder(NULL, 0))
		{
		//	printf("ast_holder\n");
			ast_holder(NULL, 1);
		}
		else
		{
		//	printf("token_list_holder\n");
			token_list_holder(NULL, 1, 0);
		}
		//printf("before heredoc\n");
		if (on_heredoc(-1))
			close(STDIN_FILENO);
		//printf("after heredoc\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		if (!is_after_prompt(-1))
			rl_redisplay();
		last_exit_status(130);
	}
}
