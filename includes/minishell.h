/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/18 12:54:29 by bmoretti         ###   ########.fr       */
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
	TOKEN_NULL,
	BLOCK,
	EXEC
};

typedef struct s_token
{
	int		type;
	char	*str;
}	t_token;

typedef struct s_ast	t_ast;
struct s_ast
{
	int			type;
	void		*content;
	t_ast		*left;
	t_ast		*right;
	t_list		*exec;
};

typedef struct s_cmd	t_cmd;
struct s_cmd
{
	char	**args;
	char	**paths;
	char	*path;
};

// exec
void	exec_single_command(t_ast *root);
char	*concat_args(t_element *el);

// code_pieces
int		create_env_vars_array(char ***env_vars);

//expands dollar sign variables
char	*env_var_value(char *key);
char	**get_paths(void);
void	clear_tree(t_ast *root);

//AST
t_ast	*ast_constructor(t_list *tokens);
int		ast_split_node(t_ast *ast_node, t_list *tokens,
	t_element *el_to_split);

//GRAMMAR CHECK
void	grammar_checker(t_list *tokens);
void	redir_and_or_pipe_rule(t_element *el);

//UTILS
int		ft_issymbol(char c);
void	ft_skip_spaces(const char **str);
void	clear_console(void);
void	panic(char *str1, char *str2, char *str3, int err_nb);
int		which_token(const char *str);
t_list	*ft_lstsplit(t_list *lst, t_element *el);

//TOKENIZER
t_list	*tokenizer(const char *str);
t_list	*token_list_holder(t_list *tokens);
void	free_token(void *p_token);
void	panic_tokenizer(char *error_msg);
void	add_token(t_list *tokens, const char **start, const char **mover, \
	int token_type);
int	add_special_token(t_list *tokens,
					const char **start, const char **mover, int token_type);
int		quotes_validation(const char *str);
int		parenthesis_validation(const char *str);

//DEBUGGERS
void	list_printer(t_list *tokens);
void	tree_execs_printer(t_ast *root);

#endif
