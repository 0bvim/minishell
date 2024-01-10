/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/10 18:52:22 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
	/* display the prompt */
	/* read user input */
	/* parser user input into commands and expand variables if have one. */
	/* search the command */
	/* create a child process (fork) */
	/* execute the command(s) (execv)*/
	/* wait for command completion */
	/* need to finish this little guide */
	/* remember to use extern **environ */

extern char	**environ;

int		main(void)
{
	char		*line;
	t_branch	*root;

	clear_console();
	line = readline("minishell~$ ");
	while (line)
	{
		if (!line || !ft_strncmp(line, "exit", 4))
			break ;
		root = tokenizer(line, NULL);
		print_tree(root);
		free_tree(root);
		line = readline("minishell~$ ");
	}
	free(line);
	return (0);
}
