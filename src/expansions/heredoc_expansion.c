/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:23:09 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/04 16:06:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_fd(int fd, char **text);

void	heredoc_expansion(t_token *token)
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
	tmp.type = token->type;
	tmp.str = text;
	close (fd);
	fd = open(token->str, TRUN, 0644);
	if (check_fd(fd, &text))
		return ;
	token_expansion((void *)(&tmp));
	ft_putstr_fd(tmp.str, fd);
	free(tmp.str);
	close (fd);
}

static int	check_fd(int fd, char **text)
{
	if (fd == -1)
	{
		perror("Error opening file");
		free(*text);
		return (1);
	}
	return (0);
}
