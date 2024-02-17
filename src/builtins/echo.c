/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:51:42 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 15:34:39 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_if_arg_minus_n(const char *arg)
{
	int	i;

	if (arg && !ft_strncmp(arg, "-n", 2))
	{
		i = 2;
		while (arg[i] == 'n')
			i++;
		if (!arg[i])
			return (1);
	}
	return (0);
}

int	echo(char **args)
{
	short int		new_line;
	short int		space;
	unsigned int	i;

	i = 1;
	space = 0;
	new_line = 1;
	while (check_if_arg_minus_n(args[i]))
	{
		i++;
		new_line = 0;
	}
	while (args[i])
	{
		if (space)
			ft_putchar_fd(' ', 1);
		else
			space++;
		ft_putstr_fd(args[i++], 1);
	}
	if (new_line)
		ft_putchar_fd('\n', 1);
	return (EXIT_SUCCESS);
}
