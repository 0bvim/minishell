/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:39:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/09 15:42:39 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//yet not tested
t_cmd	*parse_cmd(char *buffer)
{
	char	*end;
	t_cmd	*cmd;

	end = buffer + ft_strlen(buffer);
	cmd = parse_line(&buffer, end);
	peek(&buffer, end, "");
	if (buffer != end)
		panic("leftovers: ", buffer, NULL, -1);
	null_terminate(cmd);
	return (cmd);
}
