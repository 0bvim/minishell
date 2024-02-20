/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:11 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/19 21:22:43 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*key_name(const char *key_value);

static	char	**clone_env_except(char **env_vars, int except)
{
	int		i;
	int		j;
	char	**new_env;

	i = 0;
	while (env_vars[i])
		i++;
	new_env = ft_calloc(i, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = -1;
	j = -1;
	while (env_vars[++i])
	{
		if (i == except)
			continue;
		new_env[++j] = ft_strdup(env_vars[i]);
	}
	return (new_env);
}

void	ft_unsetenv(const char *name)
{
	char	**env_vars;
	char	*env_var;
	int		i;

	env_vars = environ_holder(NULL, 0);
	i = -1;
	while (env_vars[++i])
	{
		env_var = key_name(env_vars[i]);
		if (!ft_strcmp(name, env_var))
		{
			environ_holder(clone_env_except(env_vars, i), 0);
			free(env_var);
			break ;
		}
		free(env_var);
	}
}

int	unset(char **args)
{
	int		i;

	i = 0;
	while (args[++i])
		ft_unsetenv(args[i]);
	return (EXIT_SUCCESS);
}
