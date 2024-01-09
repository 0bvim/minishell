/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:48:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/09 17:43:11 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//yet untested
t_cmd	*parse_pipe(char **buffer, char *end)
{
	t_cmd	*cmd;

	cmd = parse_exec(buffer, end);
	if (peek(buffer, end, "|"))
	{
		get_token(buffer, end, NULL, NULL);
		cmd = pipe_cmd(cmd, parse_pipe(buffer, end));
	}
	return (cmd);
}
