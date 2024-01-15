/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:49:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/08 18:22:10 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern char **environ;

#include "../../includes/minishell.h"

int	create_env_vars_array(char ***env_vars)
{
	unsigned int	i;

	i = 0;
	while(environ[i++])
		;
	*env_vars = ft_calloc(i + 1, sizeof(char *));
	if (!(*env_vars))
		return (0);
	i = -1;
	while(environ[++i])
	{
		(*env_vars)[i] = ft_strdup(environ[i]);
		if (!(*env_vars)[i])
			return (0);
	}
	return (1);
}

char	*env_var_value(char *key)
{
	int		i;
	ssize_t	key_len;

	key_len = ft_strlen(key);
	i = 0;
	while (environ[i] && ft_strncmp(key, environ[i], key_len))
		i++;
	if (environ[i])
		return (environ[i] + key_len + 1);
	return (BLANK);
}

char  **get_paths(void)
{
  char  **splited_path;
  const char  *full_path = env_var_value("PATH");

  splited_path = ft_split(full_path, ':');
  return (splited_path);
}
