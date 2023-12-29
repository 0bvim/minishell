/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 01:52:11 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **envp __attribute__((unused)))
{
	/* display the prompt */
	/* read user input */
	/* parser user input into commands and expand variables if have one. */
	/* search the command */
	/* create a child process (fork) */
	/* execute the command(s) (execv)*/
	/* wait for command completion */
	/* need to finish this little guide */
	char	*input;
	while (true)
	{
		input = readline("minishell~$ ");
		if (input != NULL)
			printf("%s\n", input);
		free (input);
	}
	// printf("Hello I'm your own shell!\n");
	return (EXIT_SUCCESS);
}
