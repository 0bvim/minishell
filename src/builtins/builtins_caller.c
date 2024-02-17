/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_caller.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:08:00 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 13:36:54 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Executes the appropriate built-in command based on the given arguments.
 * 
 * @param args The array of command-line arguments.
 * @return The exit status of the executed command. -1 if no command was
 * executed.
 */
int	builtins_caller(char **args)
{
	int	exit_status;

	exit_status = -1;
	if (!args || !args[0])
		return (exit_status);
	if (!ft_strcmp(args[0], "echo"))
		exit_status = echo(args);
	else if (!ft_strcmp(args[0], "cd"))
		exit_status = cd(args);
	else if (!ft_strcmp(args[0], "pwd"))
		exit_status = pwd((const char **)args);
	else if (!ft_strcmp(args[0], "export"))
		exit_status = export(args);
	else if (!ft_strcmp(args[0], "unset"))
		exit_status = unset(args);
	else if (!ft_strcmp(args[0], "env"))
		exit_status = env((const char **)args);
	else if (!ft_strcmp(args[0], "exit"))
		builtin_exit(args);
	if (exit_status == EXIT_FAILURE || exit_status == EXIT_SUCCESS)
		last_exit_status(exit_status);
	return (exit_status);
}
