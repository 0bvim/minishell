/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:49:49 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/01 22:42:12 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	heredoc(t_ast *node_pipe)
{
	int		fd;
	char	*buff;
	const char	*ef = ((t_token *)(node_pipe->right->exec->first->content))->str;

	
	fd = open("/tmp/heredoc", O_CREAT | O_WRONLY | O_APPEND, 0000644);
	if (fd < 0)
		exit (EXIT_FAILURE); //panic
	while (1)
	{
		buff = readline("> ");
		if (ft_strncmp(buff, ef, ft_strlen(ef) + 1) == 0)
			break ;
		ft_putstr_fd(buff, fd);
		free(buff);
		buff = NULL;
	}
	free(buff);
	unlink("/tmp/heredoc");
	close(fd);
	return (STDIN_FILENO);
}
