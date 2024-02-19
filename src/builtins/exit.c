/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:57 by brmoretti         #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/18 23:12:25 by nivicius         ###   ########.fr       */
=======
/*   Updated: 2024/02/18 23:40:18 by brmoretti        ###   ########.fr       */
>>>>>>> feature/concatenate_quotes_redir
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * Sets the exit status code based on the arguments provided.
 * The exit code is converted firstly to an unsigned char to guarantee that
 * the exit status code is between 0 and 255. Then it is converted to an int.
 * @param args The arguments passed to the function.
 * @param exit_code A pointer to the exit status code variable.
 */
void	exit_status_code(char **args, int *exit_code)
{
	*exit_code = 0;
	if (args && args[1])
	{
		if (args[2])
		{
			ft_putendl_fd("exit: too many arguments", 2);
			*exit_code = 1;
		}
		else if (!ft_strisinteger(args[1]))
		{
			ft_putendl_fd("exit: numeric argument required", 2);
			*exit_code = 2;
		}
		else
			*exit_code = (int)(unsigned char)ft_atoi(args[1]);
	}
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
<<<<<<< HEAD
		ft_putendl_fd("minishell: too many arguments", STDERR_FILENO);
=======
		ft_putendl_fd(" too many arguments", STDERR_FILENO);
>>>>>>> feature/concatenate_quotes_redir
		return (EXIT_FAILURE);
	}
	exit_status_code(args, &exit_code);
	ft_clear_list(&args);
	clear_everything();
	exit(exit_code);
}
