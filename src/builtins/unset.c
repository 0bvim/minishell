/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 17:50:11 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/19 20:50:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
