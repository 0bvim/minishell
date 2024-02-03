/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:23:09 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/03 20:32:11 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void heredoc_expansion(t_token *token)
{
	char	*line;
	char	*text;
	t_token	tmp;
	int		fd;

	fd = open(token->str, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		return ;
	text = ft_calloc(1, sizeof(char));
	while (line)
	{
		text = ft_strmerge(text, line);
		line = get_next_line(fd);
	}
	tmp.type = DOUBLE_QUOTE;
	tmp.str = text;
	close (fd);
	fd = open(token->str, TRUN, 0644);
	if (fd == -1) {
		perror("Error opening file");
		free(text);
		return;
	}
	token_expansion((void *)(&tmp));
	ft_putstr_fd(tmp.str, fd);
	free(tmp.str);
	close (fd);
}
