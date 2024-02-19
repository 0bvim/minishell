/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_expansion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:23:09 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/19 01:46:42 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_fd(int fd, char **text);
static int	check_line(char *line, int fd);

void	heredoc_expansion(t_token *token)
{
	char	*line;
	char	*text;
	t_token	tmp;
	int		fd;

	fd = open(token->str, O_RDONLY);
	line = get_next_line(fd);
	if (check_line(line, fd))
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

static int	check_line(char *line, int fd)
{
	if (!line)
	{
		close(fd);
		return (1);
	}
	return (0);
}
