/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:38:23 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 14:20:10 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	success(void)
{
	char	*export_args[3];

	export_args[0] = NULL;
	export_args[1] = ft_strjoin("OLD_PWD=", static_old_pwd(NULL, 0));
	export_args[2] = NULL;
	export(export_args);
	free(export_args[1]);
	export_args[1] = ft_strjoin("PWD=", static_pwd(NULL, 0));
	export(export_args);
	free(export_args[1]);
	return (EXIT_SUCCESS);
}

void	test_exist_permission(char *path, char **pwd, int *chdir_ret)
{
	*pwd = ft_strdup(static_pwd(NULL, 0));
	if (access(path, F_OK))
		ft_putendl_fd("minishell: cd: No such file or directory", 2);
	else if (access(path, R_OK))
		ft_putendl_fd("minishell: cd: Permission denied", 2);
	*chdir_ret = chdir(path);
}

int	inexistent_directory(char *path, char *pwd)
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
	free(path);
	return (success());
}
