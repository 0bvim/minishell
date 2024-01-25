/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:49:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/25 18:09:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern char	**environ;

int	create_env_vars_array(char ***env_vars)
{
	unsigned int	i;

	i = 0;
	while (environ[i++])
		;
	*env_vars = ft_calloc(i + 1, sizeof(char *));
	if (!(*env_vars))
		return (0);
	i = -1;
	while (environ[++i])
	{
		(*env_vars)[i] = ft_strdup(environ[i]);
		if (!(*env_vars)[i])
			return (0);
	}
	return (1);
}

char	*getenv_or_blank(const char *name)
{
	char	*env_var;

	env_var = getenv(name);
	if (env_var)
		return (env_var);
	return (BLANK);
}

char	**get_paths(void)
{
	char		**splited_path;
	const char	*full_path = getenv_or_blank("PATH");

	splited_path = ft_split(full_path, ':');
	return (splited_path);
}
