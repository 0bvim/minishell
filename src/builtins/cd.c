/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:02:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 14:20:02 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		success(void);
void	test_exist_permission(char *path, char **pwd, int *chdir_ret);
int		inexistent_directory(char *path, char *pwd);

static int	test_to_change(char *path)
{
	char	*pwd;
	int		chdir_ret;
	char	*test_cwd;

	test_exist_permission(path, &pwd, &chdir_ret);
	test_cwd = getcwd(NULL, 0);
	if (!chdir_ret && !test_cwd)
		return (inexistent_directory(path, pwd));
	free(test_cwd);
	free(path);
	if (!chdir_ret)
	{
		static_old_pwd(pwd, 0);
		static_pwd(malloc_pwd(), 0);
		return (success());
	}
	free(pwd);
	return (EXIT_FAILURE);
}

static int	case_home(const char *home)
{
	if (home)
	{
		chdir(home);
		static_old_pwd(ft_strdup(static_pwd(NULL, 0)), 0);
		static_pwd(ft_strdup(home), 0);
		return (success());
	}
	ft_putendl_fd("minishell: cd: HOME not set", 2);
	return (EXIT_FAILURE);
}

int	cd(char **args)
{
	const char	*home = ft_getenv("HOME");
	char		*path;

	if (!args[1]
		|| (args[1] && !args[2] && !ft_strcmp(args[1], "~")))
		return (case_home(home));
	else if (args[2])
	{
		ft_putendl_fd("minishell: too many arguments", 2);
		return (EXIT_FAILURE);
	}
	if (args[1][0] == '~' && home)
		path = ft_strmerge(ft_strdup(home), ft_strdup(args[1] + 1));
	else
		path = ft_strdup(args[1]);
	return (test_to_change(path));
}
