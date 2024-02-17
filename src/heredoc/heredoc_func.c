/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:49:49 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/17 04:38:38 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	heredoc_file_creation(int count, int *fd, char **fl_name)
{
	*fl_name = ft_strmerge(ft_strdup("/tmp/heredoc"), ft_itoa(count));
	if (!*fl_name)
		return (0);
	*fd = open(*fl_name, TRUN, 0666);
	if (*fd >= 0)
		return (1);
	free (*fl_name);
	return (0);
}

static void	clean_heredoc_variables(char *buff, const int std_in, int fd)
{
	if (buff)
		free(buff);
	else if (g_last_signal != SIGINT)
		ft_putstr_fd("warning: here-document delimited by end-of-file\n", 2);
	close(fd);
	close (std_in);
}

static int	heredoc_loop(char **buff, t_token *token, const int std_in, int fd)
{
	on_heredoc(1);
	*buff = readline("> ");
	on_heredoc(0);
	if (g_last_signal == SIGINT)
	{
		dup2(std_in, STDIN_FILENO);
		if (*buff)
		{
			free (*buff);
			*buff = NULL;
		}
	}
	if (!*buff || !ft_strncmp(*buff, token->str, ft_strlen(token->str) + 1))
		return (0);
	ft_putstr_fd(*buff, fd);
	write(fd, "\n", 1);
	free(*buff);
	*buff = NULL;
	return (1);
}

static int	heredoc(t_token *token, int count)
{
	int			fd;
	char		*buff;
	char		*fl_name;
	const int	std_in = dup(STDIN_FILENO);

	if (!heredoc_file_creation(count, &fd, &fl_name))
		return (0);
	while (heredoc_loop(&buff, token, std_in, fd))
		;
	clean_heredoc_variables(buff, std_in, fd);
	free (token->str);
	token->str = fl_name;
	if (g_last_signal == SIGINT)
	{
		unlink(fl_name);
		return (0);
	}
	return (1);
}

int	heredoc_substitution(t_list *tokens)
{
	t_element	*el;
	t_token		*token;
	int			count;

	count = 0;
	el = tokens->first;
	while (el)
	{
		token = el->content;
		if (token->type == HEREDOC)
		{
			if (!heredoc(el->next->content, count))
			{
				token_list_holder(tokens, 1);
				return (0);
			}
			count++;
		}
		el = el->next;
	}
	return (1);
}
