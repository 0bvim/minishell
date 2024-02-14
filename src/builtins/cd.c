/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:02:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/14 20:38:31 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	success(void)
{
	char	*export_args[3];

	export_args[0] = NULL;
	export_args[2] = NULL;
	export_args[1] = ft_strjoin("OLD_PWD=", static_old_pwd(NULL, 0));
	export(export_args);
	free(export_args[1]);
	export_args[1] = ft_strjoin("PWD=", static_pwd(NULL, 0));
	export(export_args);
	free(export_args[1]);
	return (EXIT_SUCCESS);
}

void	test_first_part(const char *path, char **pwd, int *chdir_ret)
{
	*pwd = ft_strdup(static_pwd(NULL, 0));
	if (access(path, F_OK))
		ft_putstr_fd("minishell: cd: No such file or directory", 2);
	else if (access(path, R_OK))
		ft_putstr_fd("minishell: cd: Permission denied", 2);
	*chdir_ret = chdir(path);
}

int	inexistent_directory(const char *path, char *pwd)
{
	ft_putendl_fd("minishell: cd: error retrieving current directory: "
		"getcwd: cannot access parent directories: "
		"No such file or directory", 2);
	static_old_pwd(ft_strdup(pwd), 0);
	if (path[0] != '/')
		pwd = ft_strmerge(ft_strmerge(pwd, ft_strdup("/")), ft_strdup(path));
	else
		pwd = ft_strmerge(pwd, ft_strdup(path));
	static_pwd(pwd, 0);
	return (success());
}

int	test_to_change(const char *path)
{
	char	*pwd;
	int		chdir_ret;
	char	*test_cwd;

	test_first_part(path, &pwd, &chdir_ret);
	test_cwd = getcwd(NULL, 0);
	if (!chdir_ret && !test_cwd)
		return (inexistent_directory(path, pwd));
	free(test_cwd);
	if (!chdir_ret)
	{
		static_old_pwd(pwd, 0);
		static_pwd(malloc_pwd(), 0);
		return (success());
	}
	free(pwd);
	return (EXIT_FAILURE);
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
	return (test_to_change(args[1]));
}
