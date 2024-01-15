/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/15 16:49:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

/* for read line (compile with -lreadline or just -l) */
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

/* malloc, free, write, printf, getcwd, chdir, stat, lstat and others */
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <termios.h>

/* access, open read, close */
# include <fcntl.h>

/* fork, wait family */
# include <sys/types.h>
# include <sys/wait.h>

/* signal family */
# include <signal.h>

/* libft header path */
# include "../lib/libft/include/libft.h"

# define SYMBOLS "&|<>()'\"$"
# define BLANK ""

/* enum and struct */

enum	e_token
{
	ARGUMENT,
	PIPE,
	DOLLAR,
	AND,
	OR,
	L_PAREN,
	R_PAREN,
	QUOTE,
	DOUBLE_QUOTE,
	L_REDIR,
	HEREDOC,
	R_REDIR,
	APPEND,
	TOKEN_NULL
};

typedef	struct s_token
{
	int		type;
	char	*str;
}	t_token;

// code_pieces
int		create_env_vars_array(char ***env_vars);
//expands dollar sign variables
char	*env_var_value(char *key);

//GRAMMAR CHECK
void	grammar_checker(t_list *tokens);
void	redir_and_or_rule(t_element *el);

//UTILS
int		ft_issymbol(char c);
void	ft_skip_spaces(const char **str);
void	clear_console(void);
void	panic(char *str1, char *str2, char *str3, int err_nb);
int		which_token(const char *str);

//TOKENIZER
t_list	*tokenizer(const char *str);
t_list	*token_list_holder(t_list *tokens);
void	free_token(void *p_token);
void	panic_tokenizer(char *error_msg);
void	add_token(t_list *tokens, const char **start, const char **mover, int token_type);
void	add_quotes_token(t_list *tokens, const char **start, const char **mover, int token_type);
void	add_symbols_token(t_list *tokens, const char **start, const char **mover, int token_type);
int		quotes_validation(const char *str);
int		parenthesis_validation(const char *str);

//DEBUGGERS
void	list_printer(t_list *tokens);

#endif
