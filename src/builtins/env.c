/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:15 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/02 11:52:39 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern char	**environ;

int	env(const char **args)
{
	int		i;
	char	**env_vars;

	if (args[1])
	{
		ft_putendl_fd("minishell: env doesn't accept arguments or flags", 2);
		return (EXIT_FAILURE);
	}
	i = 0;
	env_vars = environ_holder(NULL, 0);
	while (env_vars[i])
		ft_putendl_fd(environ[i++], 1);
	return (EXIT_SUCCESS);
}
