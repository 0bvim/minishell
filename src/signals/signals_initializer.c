/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:32:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/18 14:22:01 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_initializer(void)
{
	if (signal(SIGINT, sigint_handler) == SIG_ERR
		|| signal(SIGQUIT, SIG_IGN) == SIG_ERR)
	{
		ft_putendl_fd("fail to set signals", 2);
		exit (EXIT_FAILURE);
	}
}

int	is_after_prompt(int is_after)
{
	static int	after;

	if (is_after != -1)
		after = is_after;
	return (after);
}

int	on_heredoc(int on_heredoc)
{
	static int	heredoc;

	if (on_heredoc != -1)
		heredoc = on_heredoc;
	return (heredoc);
}

void	sigquit_case(void)
{
	if (last_exit_status(-1) == 131)
	{
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
		term_properties(1);
	}
	else
		term_properties(0);
}
