/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:02:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/04 19:02:30 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	success(void)
{
	char	*export_args[3];
	char	*pwd;

	export_args[0] = NULL;
	export_args[2] = NULL;
	export_args[1] = ft_strjoin("OLDPWD=", ft_getenv("PWD"));
	export(export_args);
	free(export_args[1]);
	pwd = malloc_pwd();
	export_args[1] = ft_strjoin("PWD=", pwd);
	export(export_args);
	free(pwd);
	free(export_args[1]);
	return (EXIT_SUCCESS);
}

int	cd(char **args)
{
	if (!args[1])
	{
		if (ft_getenv("HOME"))
		{
			chdir(ft_getenv("HOME"));
			return (success());
		}
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (EXIT_FAILURE);
	}
	else if (args[2])
	{
		ft_putendl_fd("minishell: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	else if (chdir(args[1]))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	return (success());
}
