/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:02:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/01 18:08:44 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	cd(char **args)
{
	if (!args[1])
	{
		if (ft_getenv("HOME"))
		{
			chdir(ft_getenv("HOME"));
			return (EXIT_SUCCESS);
		}
		ft_putendl_fd("minishell: cd: HOME not set", 2);
		return (EXIT_FAILURE);
	}
	else if (args[2])
	{
		ft_putendl_fd("minishell: too many arguments to \"cd\"", 2);
		return (EXIT_FAILURE);
	}
	else if (chdir(args[1]))
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
