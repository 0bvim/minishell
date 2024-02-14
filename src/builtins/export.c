/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:03 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/14 20:49:40 by brmoretti        ###   ########.fr       */
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
		new_env_vars[i] = ft_strdup(env_vars[i]);
	new_env_vars[i] = new_env_var;
	new_env_vars[++i] = NULL;
	environ_holder(NULL, 1);
	environ_holder(new_env_vars, 0);
}

static void	ft_setenv(const char *name, const char *value)
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

int	is_valid_identifier(char *str)
{
	if (*str != '=' && !ft_isdigit(*str))
	{
		while (*str && *str != '=' && (ft_isalnum(*str) || *str == '_'))
			str++;
		if (*str == '=' || !*str)
			return (1);
	}
	ft_putendl_fd("minishell: export: not a valid identifier", 2);
	last_exit_status(1);
	return (0);
}

int	export(char **args)
{
	int		i;
	char	*equal_sign;
	char	*name;
	int		status;

	i = 0;
	status = 0;
	while (args[++i])
	{
		if (!is_valid_identifier(args[i]) && status++)
			continue ;
		equal_sign = ft_strchr(args[i], '=');
		if (equal_sign)
		{
			name = ft_strndup(args[i], equal_sign - args[i]);
			if (!name)
				return (EXIT_FAILURE);
			ft_setenv(name, equal_sign + 1);
			free(name);
		}
	}
	return (!!status);
}
