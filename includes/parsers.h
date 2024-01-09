/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:40:55 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/09 15:41:03 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERS_H
# define PARSERS_H

typedef struct s_cmd
{
	int	type;
}	t_cmd;

t_cmd	*parse_cmd(char *buffer);

//to do:
t_cmd	*parse_line(char **buffer, char *end);
t_cmd	*null_terminate(struct cmd *cmd);

#endif
