/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/10 17:50:13 by brmoretti        ###   ########.fr       */
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

static void	parser(char *input);
static void	remove_quotes(void *content);

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

static void	parser(char *input)
{
	t_list	*tokens;
	t_ast	*root;

	tokens = tokenizer(input);
	free(input);
	if (!tokens)
		return ;
	if (grammar_checker(tokens))
		return ;
	ft_lstiter(tokens, remove_quotes);
	if (!heredoc_substitution(tokens))
		return ;
	root = ast_constructor(tokens);
	if (!root)
		return ;
	ast_holder(root, 0);
	execution(root);
	ast_holder(NULL, 1);
}

static void	remove_quotes(void *content)
{
	t_token	*token;
	char	*tmp;

	token = content;
	if (token->type == QUOTE || token->type == DOUBLE_QUOTE)
	{
		tmp = ft_strndup(token->str + 1, ft_strlen(token->str) - 2);
		free(token->str);
		token->str = tmp;
	}
}
