/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 11:51:42 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/24 16:36:57 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	echo(const char **args)
{
	short int		new_line;
	short int		space;
	unsigned int	i;

	i = 1;
	space = 0;
	new_line = 1;
	if (!ft_strncmp(args[1], "-n", 3) && ++i)
		new_line = 0;
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
