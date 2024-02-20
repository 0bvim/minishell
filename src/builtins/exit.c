/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:57 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/20 10:57:08 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	treat_as_number(char *str)
{
	char			*mover;
	size_t			nb_len;
	const size_t	max_nb_len = ft_strlen(MAX_NB);

	if (!ft_strisinteger(str))
		return (0);
	mover = str;
	if (*mover == '-' || *mover == '+')
		mover++;
	while (*mover == '0')
		mover++;
	nb_len = ft_strlen(mover);
	if (nb_len < max_nb_len)
		return (1);
	if (nb_len > max_nb_len)
		return (0);
	if (*str == '-')
		return (ft_strcmp(&MIN_NB[1], mover) >= 0);
	return (ft_strcmp(mover, &MAX_NB[0]) <= 0);
}

/**
 * Sets the exit status code based on the arguments provided.
 * The exit code is converted firstly to an unsigned char to guarantee that
 * the exit status code is between 0 and 255. Then it is converted to an int.
 * @param args The arguments passed to the function.
 * @param exit_code A pointer to the exit status code variable.
 */
static int	exit_status_code(char **args)
{
	if (args && args[1])
	{
		if (args[2])
		{
			ft_putendl_fd("exit: too many arguments", 2);
			return (1);
		}
		else if (!treat_as_number(args[1]))
		{
			ft_putendl_fd("exit: numeric argument required", 2);
			return (2);
		}
		else
			return((int)(unsigned char)ft_atoi(args[1]));
	}
	return (0);
}

void	clear_everything(void)
{
	ast_holder(NULL, 1);
	environ_holder(NULL, 1);
	static_pwd(NULL, 1);
	static_old_pwd(NULL, 1);
	close(STDIN_FILENO);
	close(STDOUT_FILENO);
	close(STDERR_FILENO);
}

int	builtin_exit(char **args)
{
	int	exit_code;

	if (!is_fork(-1))
		ft_putendl_fd("exit", 2);
	if (args[1] && args[2])
	{
		ft_putendl_fd("minishell: too many arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	exit_code = exit_status_code(args);
	ft_clear_list(&args);
	clear_everything();
	exit(exit_code);
}
