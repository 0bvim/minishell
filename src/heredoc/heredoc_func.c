/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:49:49 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/10 19:18:45 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	heredoc(t_token *token, int count)
{
	int			fd;
	char		*buff;
	char		*fl_name;

	fl_name = ft_strmerge(ft_strdup("/tmp/heredoc"), ft_itoa(count));
	fd = open(fl_name, HERE, 0644);
	if (fd < 0)
		return (0);
	while (1)
	{
		buff = readline("> ");
		if (!buff || !ft_strncmp(buff, token->str, ft_strlen(token->str) + 1))
			break ;
		ft_putstr_fd(buff, fd);
		write(fd, "\n", 1);
		free(buff);
		buff = NULL;
	}
	if (buff)
		free(buff);
	else
		ft_putstr_fd("warning: here-document delimited by end-of-file\n", 2);
	free (token->str);
	close(fd);
	token->str = fl_name;
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
