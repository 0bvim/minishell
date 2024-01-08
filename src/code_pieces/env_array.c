/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:49:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/08 14:07:50 by brmoretti        ###   ########.fr       */
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
	*env_vars = ft_calloc(i, sizeof(char *));
	if (!*env_vars)
		return (0);
	i = 0;
	while(environ[i])
	{
		(*env_vars)[i] = ft_strdup(environ[i]);
		if (!(*env_vars)[i])
			return (0);
		i++;
	}
	return (0);
}

char	*env_var_value(char *key)
{
	int		i;
	ssize_t	key_len;

	key_len = ft_strlen(key);
	while (ft_strncmp(key, environ[i], key_len))
		i++;
	if (environ[i])
		return (environ[i] + key_len + 2);
	return (NULL);
}


