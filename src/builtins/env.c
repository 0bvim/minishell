/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:18:15 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/24 16:33:35 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

extern char	**environ;

void	env(const char **args)
{
	int	i;

	if (args[1])
	{
		ft_putendl_fd("minishell: env doesn't accept arguments or flags", 2);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (environ[i])
		ft_putendl_fd(environ[i++], 1);
	exit(EXIT_SUCCESS);
}
