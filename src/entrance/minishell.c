/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/02 18:41:26 by bmoretti         ###   ########.fr       */
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
	signals_initializer();
	environ_initializer();
	while (true)
	{
		g_last_signal = 0;
		parser(prompt());
	}
	return (EXIT_SUCCESS);
}

char	*prompt(void)
{
	char	*input;

	is_after_prompt(0);
	input = readline("minishell>$ ");
	is_after_prompt(1);
	add_history(input);
	if (!input)
		input = ft_strdup("exit");
	return (input);
}

void	parser(char *input)
{
	t_list	*tokens;
	t_ast	*root;

	tokens = tokenizer(input);
	free(input);
	if (!tokens)
		return ;
	if (grammar_checker(tokens))
		return ;
	heredoc_substitution(tokens);
	root = ast_constructor(tokens);
	if (!root)
		return ;
	ast_holder(root, 0);
	execution(root);
	ast_holder(NULL, 1);
}
