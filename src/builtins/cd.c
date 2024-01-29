/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:02:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/29 17:03:29 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd_no_args(const char *arg_1, char **go_to)
{
	char	*home;
	
	if (arg_1 == NULL)
	{
		home = ft_getenv("HOME");
		if (!home)
			*go_to = NULL;
		else
			*go_to = ft_strdup(home);
		return (1);
	}
	return (0);
}

int	cd(const char **args)
{
	char	*go_to;
	char	*cwd;

	if (args[2])
	{
		ft_putendl_fd("minishell: too many arguments to \"cd\"", 2);
		return (EXIT_FAILURE);
	}
	if (cd_no_args(args[1], &go_to))
		;
	else if (chdir(args[1]))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
	}
	else
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}