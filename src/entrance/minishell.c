/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/03 18:06:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_token	*tokenize(char *input);
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
	t_token	*token;

	clear();
	token = NULL;
	while (true)
	{
		input = readline("minishell~$ ");
		if (input != NULL)
		{
			token = tokenize(input);
			printf("%d\n", token->type);
			printf("%s\n", token->value);
		}
		free (input);
		free (token);
	}
	return (EXIT_SUCCESS);
}
