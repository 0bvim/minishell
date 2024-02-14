/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_initializer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:32:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/14 10:53:48 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signals_initializer(void)
{
	if (signal(SIGINT, signal_handler) == SIG_ERR
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
