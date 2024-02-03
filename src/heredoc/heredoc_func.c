/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:49:49 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/03 03:00:34 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	heredoc(t_token *token, char *count)
{
	int			fd;
	char		*buff;
	char		*fl_name;

	fl_name = ft_strmerge(ft_strdup("/tmp/heredoc"), ft_strdup(count));
	fd = open(fl_name, HERE, 0644);
	if (fd < 0)
		exit (EXIT_FAILURE); //panic
	while (1)
	{
		buff = readline("> ");
		if (ft_strncmp(buff, token->str, ft_strlen(token->str) + 1) == 0)
			break ;
		ft_putstr_fd(buff, fd);
		write(fd, "\n", 1);
		free(buff);
		buff = NULL;
	}
	free(buff);
	free (token->str);
	close(fd);
	token->str = fl_name;
}

void	heredoc_substitution(t_list *tokens)
{
	t_element	*el;
	t_token		*token;
	char		count;

	count = '0';
	el = tokens->first;
	while (el)
	{
		token = el->content;
		if (token->type == HEREDOC)
		{
			heredoc(el->next->content, &count);
			count++;
		}
		el = el->next;
	}
}
