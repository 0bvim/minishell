/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:49:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/04 18:53:07 by bmoretti         ###   ########.fr       */
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

#include <stdio.h>

int	main(void)
{
	char **env_vars;

	create_env_vars_array(&env_vars);
	printf("%s\n", env_vars[0]);
	return (0);
}
