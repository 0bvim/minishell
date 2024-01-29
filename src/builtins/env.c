/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:15 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/29 15:48:26 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern char	**environ;

void	env(const char **args)
{
	int		i;
	char	**env_vars;

	if (args[1])
	{
		ft_putendl_fd("minishell: env doesn't accept arguments or flags", 2);
		exit(errno);
	}
	i = 0;
	env_vars = environ_holder(NULL, 0);
	while (env_vars[i])
		ft_putendl_fd(environ[i++], 1);
	exit(EXIT_SUCCESS);
}
