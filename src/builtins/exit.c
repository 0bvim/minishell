/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:57 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/04 19:34:51 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_status_code(char **args, int *exit_code)
{
	*exit_code = 0;
	if (args[1])
	{
		if (args[2])
		{
			ft_putendl_fd("exit: too many arguments", 2);
			*exit_code = 1;
		}
		else if (!ft_strisinteger(args[1]))
		{
			ft_putendl_fd("exit: numeric argument required", 2);
			*exit_code = 2;
		}
		else
			*exit_code = (int)(unsigned char)ft_atoi(args[1]);
	}
}

void	builtin_exit(char **args)
{
	int	exit_code;

	exit_status_code(args, &exit_code);
	ft_clear_list(&args);
	ast_holder(NULL, 1);
	environ_holder(NULL, 1);
	ft_putendl_fd("exit", 1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
	exit((int)exit_code);
}
