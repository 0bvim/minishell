/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_caller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:08:00 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/29 23:27:24 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtins_caller(char **args)
{
	int	exit_status;

	exit_status = -1;
	if (ft_strncmp(args[0], "echo", 5) == 0)
		exit_status = echo(args);
	// else if (ft_strcmp(args[0], "cd") == 0)
	// 	builtin_cd(args);
	else if (ft_strncmp(args[0], "pwd", 4) == 0)
		exit_status = pwd((const char **)args);
	else if (ft_strncmp(args[0], "export", 7) == 0)
		exit_status = export(args);
	else if (ft_strncmp(args[0], "unset", 6) == 0)
		exit_status = unset(args);
	else if (ft_strncmp(args[0], "env", 4) == 0)
		exit_status = env((const char **)args);
	else if (ft_strncmp(args[0], "exit", 5) == 0)
		builtin_exit(args);
	if (exit_status != -1)
		ft_clear_list(&args);
	if (exit_status == EXIT_SUCCESS)
		clean_exit_ast();
	else if (exit_status == EXIT_FAILURE)
		panic_ast(EXIT_FAILURE, NULL);
}
