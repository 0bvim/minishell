/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 15:15:21 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/26 18:59:59 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		if (ast_holder(NULL))
			panic_ast(130, "");
		rl_on_new_line();
		rl_replace_line("", 0);
		ft_putstr_fd("\n", 1);
		if (!is_after_prompt(-1))
			rl_redisplay();
		last_exit_status(130);
	}
	return ;
}
