/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/29 15:28:49 by brmoretti        ###   ########.fr       */
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

volatile int	g_last_signal;
extern char		**environ;

void		parser(char *input);

int	main(void)
{
	pid_t	pid;
	char	*input;

	signals_initializer();
	environ_initializer();
	while (true)
	{
		input = prompt();
		g_last_signal = 0;
		pid = fork();
		if (pid == -1)
			ft_putstr_fd("fork error\n", 2);
		if (pid == 0)
			parser(input);
		pid_last_exit_status(pid);
		if (g_last_signal == SIGINT)
			last_exit_status(130);
		free(input);
	}
	environ_holder(NULL, 1);
	return (EXIT_SUCCESS);
}

char	*prompt(void)
{
	char	*input;

	is_after_prompt(0);
	input = readline("minishell>$ ");
	is_after_prompt(1);
	add_history(input);
	if (!(input != NULL && ft_strncmp(input, "exit", 4)))
	{
		ft_putendl_fd("exit", 1);
		environ_holder(NULL, 1);
		exit(EXIT_SUCCESS);
	}
	return (input);
}

void	parser(char *input)
{
	t_list	*tokens;
	t_ast	*root;

	tokens = tokenizer(input);
	free(input);
	grammar_checker(tokens);
	root = ast_constructor(tokens);
	ast_holder(root);
	execution(root);
	clear_tree(root);
}
