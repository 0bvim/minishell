/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/11 22:47:36 by brmoretti        ###   ########.fr       */
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
int	main(void)
{
	char	*input;
	t_list	*quotes_delimited;

	clear_console();
	while (true)
	{
		input = readline("minishell~$ ");
		if (input != NULL && ft_strncmp(input, "exit", 4))
		{
			//printf("%s\n", input);
			quotes_delimited = treat_quotes_init(input);
			free (quotes_delimited);
			free (input);
		}
		else
			break;
	}
	free(input);
	return (EXIT_SUCCESS);
}
