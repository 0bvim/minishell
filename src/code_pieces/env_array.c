/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:49:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/19 21:31:48 by vde-frei         ###   ########.fr       */
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
	char	**temp_env;

	temp_env = __environ;
	__environ = environ_holder(NULL, 0);
	env_var = getenv(name);
	__environ = temp_env;
	if (env_var)
		return (env_var);
	return (BLANK);
}
