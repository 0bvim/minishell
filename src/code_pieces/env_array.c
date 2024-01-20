/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:49:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/20 15:32:23 by bmoretti         ###   ########.fr       */
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

char	*env_var_value(const char *key)
{
	int		i;
	size_t	key_len;
	size_t	comparison;

	key_len = ft_strlen(key);
	i = 0;
	while (environ[i])
	{
		comparison = ft_strchr(environ[i], '=') - environ[i];
		if (comparison < key_len)
			comparison = key_len;
		if (!ft_strncmp(key, environ[i], comparison))
			break ;
		i++;
	}
	if (environ[i])
		return (environ[i] + comparison + 1);
	return (BLANK);
}

char	**get_paths(void)
{
	char		**splited_path;
	const char	*full_path = env_var_value("PATH");

	splited_path = ft_split(full_path, ':');
	return (splited_path);
}
