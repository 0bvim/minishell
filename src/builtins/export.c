/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:03 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/29 17:00:55 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_to_env(const char *new_env_var)
{
	char	**env_vars;
	char	**new_env_vars;
	int		i;

	env_vars = environ_holder(NULL, 0);
	i = 0;
	while (env_vars[i])
		i++;
	new_env_vars = malloc(sizeof(char *) * (i + 2));
	i = -1;
	while (env_vars[++i])
		new_env_vars[i] = env_vars[i];
	new_env_vars[i++] = new_env_var;
	new_env_vars[i] = NULL;
	free(env_vars);
	environ_holder(new_env_vars, 0);
}

void	ft_setenv(const char *name, const char *value)
{
	char	**env_vars;
	char	*new_env_var;
	char	*temp;
	int		i;

	env_vars = environ_holder(NULL, 0);
	temp = ft_strjoin(name, "=");
	new_env_var = ft_strjoin(temp, value);
	i = -1;
	while (env_vars[++i])
	{
		if (!ft_strncmp(env_vars[i], temp, ft_strlen(temp)))
		{
			free(temp);
			free(env_vars[i]);
			env_vars[i] = new_env_var;
			return ;
		}
	}
	free(temp);
	add_to_env(new_env_var);
}

void	export(const char **args)
{
	int		i;
	char	*equal_sign;
	char	*name;

	i = 0;
	name = NULL;
	while (args[++i])
	{
		equal_sign = ft_strchr(args[i], '=');
		if (equal_sign)
		{
			if (equal_sign == args[i])
			{
				ft_putendl_fd("minishell: export:\
				 `=': not a valid identifier", 2);
				exit(EXIT_FAILURE);
			}
			name = ft_strndup(args[i], equal_sign - args[i]);
			if (!name)
				exit(EXIT_FAILURE);
			ft_setenv(name, equal_sign + 1);
			free(name);
		}
	}
}
