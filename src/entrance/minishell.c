/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/19 18:13:44 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

volatile int	g_last_signal;

void	term_properties(int restore)
{
	static struct termios	term;

	if (!restore)
		tcgetattr(STDIN_FILENO, &term);
	else
		tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

int	main(void)
{
	signals_initializer();
	environ_initializer();
	static_pwd(malloc_pwd(), 0);
	term_properties(0);
	while (true)
	{
		sigquit_case();
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
	if (!input)
		input = ft_strdup("exit");
	if (ft_strcmp(input, ""))
		add_history(input);
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
	ft_lstiter(tokens, trim_edges);
	if (grammar_checker(tokens))
		return ;
	if (!heredoc_substitution(tokens))
		return ;
	root = ast_constructor(tokens);
	if (!root)
		return ;
	token_list_holder(NULL, 0, 1);
	ast_holder(root, 0);
	execution(root);
	ast_holder(NULL, 1);
}
