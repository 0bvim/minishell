/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:49:49 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/02 11:55:21 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_infile(t_ast *node_pipe)
{
	const int	tmp = dup(STDIN_FILENO);

	dup2(open("/tmp/heredoc", O_RDONLY), STDIN_FILENO);
	execution(node_pipe->left);
	dup2(tmp, STDIN_FILENO);
	close (tmp);
}

int	heredoc(t_ast *node_pipe)
{
	int			fd;
	char		*buff;
	const char	*ef = ((t_token*)(node_pipe->right->exec->first->content))->str;

	fd = open("/tmp/heredoc", O_CREAT | O_WRONLY | O_APPEND, 0000644);
	if (fd < 0)
		exit (EXIT_FAILURE); //panic
	while (1)
	{
		buff = readline("> ");
		if (ft_strncmp(buff, ef, ft_strlen(ef) + 1) == 0)
			break ;
		ft_putstr_fd(buff, fd);
		write(fd, "\n", 1);
		free(buff);
		buff = NULL;
	}
	free(buff);
	handle_infile(node_pipe);
	unlink("/tmp/heredoc");
	close(fd);
	return (STDIN_FILENO);
}
