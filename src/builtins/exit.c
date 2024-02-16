/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:57 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/16 12:51:54 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exit_status_code(char **args, int *exit_code)
{
	*exit_code = 0;
	if (args && args[1])
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

void	clear_everything(void)
{
	ast_holder(NULL, 1);
	environ_holder(NULL, 1);
	static_pwd(NULL, 1);
	static_old_pwd(NULL, 1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

void	builtin_exit(char **args)
{
	int	exit_code;

	exit_status_code(args, &exit_code);
	ft_putendl_fd("exit", 1);
	ft_clear_list(&args);
	clear_everything();
	exit((int)exit_code);
}
