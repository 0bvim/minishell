/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:03 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/01 18:00:00 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_to_env(char *new_env_var)
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
	new_env_vars[i] = new_env_var;
	new_env_vars[++i] = NULL;
	environ_holder(NULL, 1);
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

int	export(char **args)
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
				return(EXIT_FAILURE);
			}
			name = ft_strndup(args[i], equal_sign - args[i]);
			if (!name)
				return(EXIT_FAILURE);
			ft_setenv(name, equal_sign + 1);
			free(name);
		}
	}
	return(EXIT_SUCCESS);
}
