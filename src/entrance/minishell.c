/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/27 16:48:52 by bmoretti         ###   ########.fr       */
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

void		parser(char *input);

int	main(void)
{
	pid_t	pid;
	char	*input;

	signals_initializer();
	while (true)
	{
		g_last_signal = 0;
		input = prompt();
		pid = fork();
		if (pid == -1)
			ft_putstr_fd("fork error\n", 2);
		if (pid == 0)
			parser(input);
		pid_last_exit_status(pid);
		if (g_last_signal == SIGINT)
			last_exit_status(130);
		if (input)
			free(input);
	}
	return (EXIT_SUCCESS);
}

int	is_after_prompt(int is_after)
{
	static int	after;

	if (is_after != -1)
		after = is_after;
	return (after);
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
		exit(EXIT_SUCCESS);
	}
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
	clear_tree(root);
}
