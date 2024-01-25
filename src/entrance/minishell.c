/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/25 18:37:37 by bmoretti         ###   ########.fr       */
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
/* remember to use extern **environ */

static char	*prompt(void);
void		parser(char *input);

int	main(void)
{
	pid_t	pid;
	char	*input;

	clear_console();
	while (true)
	{
		input = prompt();
		pid = fork();
		if (pid == -1)
			ft_putstr_fd("fork error\n", 2);
		if (pid == 0)
			parser(input);
		last_exit_status(pid);
		if (input)
			free(input);
	}
	return (EXIT_SUCCESS);
}

static char	*prompt(void)
{
	char	*input;

	input = readline("minishell~$ ");
	add_history(input);
	if (!(input != NULL && ft_strncmp(input, "exit", 4)))
		exit(EXIT_SUCCESS);
	return (input);
}

void	parser(char *input)
{
	t_list	*tokens;
	t_ast	*root;

	tokens = tokenizer(input);
	grammar_checker(tokens);
	root = ast_constructor(tokens);
	ast_holder(root);
	execution(root);
	// tree_execs_printer(root);
	// free(input);
	clear_tree(root);
}
