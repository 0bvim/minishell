/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:23:09 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/03 13:02:28 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void heredoc_expansion(t_token *token, int *fd)
{
	char	*line;
	char	*text;
	t_token	tmp;
	
	line = get_next_line(*fd);
	if (!line)
		return ;
	text = ft_calloc(1, sizeof(char));
	while (line)
	{
		text = ft_strmerge(text, line);
		line = get_next_line(*fd);
	}
	// unlink(token->str);
	// free(token->str);
	// token->type = DOUBLE_QUOTE;
	// token->str = text;
	tmp.type = DOUBLE_QUOTE;
	tmp.str = text;
	close(*fd);
	*fd = open(token->str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	token_expansion((void *)(&tmp));
	write(*fd, tmp.str, ft_strlen(tmp.str));
}