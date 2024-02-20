/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:08:03 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/19 21:38:38 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_environ_sorted(void);
char	*key_name(const char *key_value);
int		is_valid_identifier(char *str);

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

static char	*new_env_var_generator(const char *name, const char *value)
{
	char	*new_env_var;
	char	*eq_value;
	char	*tmp;

	if (!value)
		return (ft_strdup(name));
	if (*value != '\"')
	{
		if (*value == '\'')
			eq_value = ft_strndup(value + 1, ft_strlen(value) - 2);
		else
			eq_value = ft_strdup(value);
		tmp = ft_strjoin("\"", eq_value);
		free (eq_value);
		eq_value = ft_strjoin(tmp, "\"");
		free (tmp);
	}
	else
		eq_value = ft_strdup(value);
	tmp = eq_value;
	eq_value = ft_strjoin("=", eq_value);
	free (tmp);
	new_env_var = ft_strjoin(name, eq_value);
	free (eq_value);
	return (new_env_var);
}

static void	ft_setenv(const char *name, const char *value)
{
	char	**env_vars;
	char	*new_env_var;
	char	*env_var;
	int		i;

	env_vars = environ_holder(NULL, 0);
	new_env_var = new_env_var_generator(name, value);
	i = -1;
	while (env_vars[++i])
	{
		env_var = key_name(env_vars[i]);
		if (!ft_strcmp(env_var, name))
		{
			free(env_var);
			free(env_vars[i]);
			env_vars[i] = new_env_var;
			return ;
		}
		free (env_var);
	}
	add_to_env(new_env_var);
}

int	export(char **args)
{
	int		i;
	char	*equal_sign;
	char	*name;
	int		status;

	i = 0;
	status = 0;
	if (!args[1])
		print_environ_sorted();
	while (args[++i])
	{
		if (!is_valid_identifier(args[i]) && status++)
			continue ;
		name = key_name(args[i]);
		equal_sign = ft_strchr(args[i], '=');
		if (equal_sign)
			ft_setenv(name, equal_sign + 1);
		else
			ft_setenv(name, NULL);
		free(name);
	}
	return (!!status);
}
