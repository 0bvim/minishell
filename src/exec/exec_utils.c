/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:20:03 by nivicius          #+#    #+#             */
/*   Updated: 2024/02/20 12:24:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	clean_pwd(void)
{
	static_pwd(NULL, 1);
	static_old_pwd(NULL, 1);
}

int	search_command(char *exec_name)
{
	char	**paths;
	char	*cmd;
	int		i;

	i = 0;
	paths = ft_split(ft_getenv("PATH"), ':');
	if (!paths)
		return (1);
	while (paths[i])
	{
		cmd = ft_strmerge(ft_strjoin(paths[i], "/"), ft_strdup(exec_name));
		if (access(cmd, F_OK) == 0)
		{
			ft_clear_list(&paths);
			free (cmd);
			return (1);
		}
		free(cmd);
		cmd = NULL;
		i++;
	}
	ft_clear_list(&paths);
	return (0);
}

void	treat_errors(char *path)
{
	if (access(path, R_OK | W_OK) == -1 && !access(path, F_OK))
		panic_ast(126, "minishell: Permission denied");
	else if ((*path == '/' || *path == '.') && !access(path, F_OK))
		panic_ast(126, "minishell: Is a directory");
	else if (!search_command(path) && !(*path == '/' || *path == '.'))
		panic_ast(127, "minishell: command not found");
	else if (!search_command(path) || !ft_getenv("PATH"))
		panic_ast(127, "minishell: No such file or directory");
	else
		panic_ast(!!errno, NULL);
	close_fds();
	clean_pwd();
}
