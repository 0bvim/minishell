/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_exit_status.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:11:29 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/25 16:44:22 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	last_exit_status(pid_t pid)
{
	static int	status;

	if (pid)
	{
		waitpid(pid, &status, 0);
		//status = (((status) & 0xff00) >> 8);
	}
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (status);
}
