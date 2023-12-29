/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 16:14:09 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

Token	*tokenize(char *input);
	/* display the prompt */
	/* read user input */
	/* parser user input into commands and expand variables if have one. */
	/* search the command */
	/* create a child process (fork) */
	/* execute the command(s) (execv)*/
	/* wait for command completion */
	/* need to finish this little guide */
int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **envp __attribute__((unused)))
{
	char	*input;
	Token	*token;

	while (true)
	{
		input = readline("minishell~$ ");
		if (input != NULL)
		{
			token = tokenize(input);
		}
		free (input);
	}
	return (EXIT_SUCCESS);
}
