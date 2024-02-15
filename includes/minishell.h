/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2024/02/15 20:06:17 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

/*errors*/
# include <errno.h>

# define SYMBOLS "&|<>()'\""
# define BLANK ""
# define TRUN 0x00000242
# define APEN 0x00000442
# define HERE 0x00000241

extern volatile int	g_last_signal;

/* enum and struct */

enum	e_token
{
	ARGUMENT = 1,
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

enum	e_flags
{
	READ,
	WRITE
};

typedef struct s_token
{
	int		type;
	char	*str;
	char	next_char;
}	t_token;

typedef struct s_ast
{
	int					type;
	int					type_prev;
	int					set_fd;
	int					fd;
	int					error;
	int					old_file;
	int					infile_set;
	int					outfile_set;
	int					first_infile_err;
	int					first_outfile_err;
	int					fake_file;
	char				buff[1];
	char				*tmp_file;
	struct s_ast		*left;
	struct s_ast		*right;
	t_list				*exec;
}	t_ast;

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
}	t_cmd;

//ENTRANCE
void		environ_initializer(void);
char		*static_pwd(char *new_pwd, int to_free);
char		*static_old_pwd(char *new_pwd, int to_free);
char		**environ_holder(char **new_environ, int to_free);

//BUILTINS
char		*malloc_pwd(void);
int			cd(char **args);
int			builtins_caller(char **args);
int			echo(char **args);
int			env(const char **args);
void		builtin_exit(char **args);
int			export(char **args);
int			pwd(const char **args);
int			unset(char **args);

//prompt
char		*prompt(void);
int			is_after_prompt(int is_after);

//pipe handling
int			handle_pipe(t_ast *node_pipe);

//handle redirs
int			heredoc_substitution(t_list *tokens);
int			is_redirect_in(int type);
int			is_redirect_out(int type);
int			check_infile(t_ast *node);
int			append_trunc(t_ast *node, int flag);
int			open_file_error(char *file_name);
int			input_redir(t_ast *node);
int			file_err(t_ast *node, t_token *tk, const int *tmp);
void		handle_redirs(t_ast *node_pipe);
void		substitute_first_token_str(t_list *tokens);
void		set_fd_in(t_ast *node);
void		set_fd_out(t_ast *node);
void		set_next_node(t_ast *node);
void		set_next_node_err(t_ast *node);
void		temp_fd(t_ast *node);
void		handle_infile(t_ast *node, t_token *token, int *file);
void		handle_outfile(t_ast *node, int *file);
void		outfile_error(t_ast *node, t_token *token);
void		node_left_error(t_ast *nod, t_token *tk, const int *tmp, int *file);
void		close_tmp(const int *tmp);
void		after_ex(t_ast *node, int *file, const int *tmp);
void		infile_after(t_ast *node, const int *tmp);
void		init_redirs(t_ast *node, t_token **tk, int *file);
void		seek_and_destroy(t_ast *node, int *file, const int *tmp);

//handle && and ||
void		handle_and_or(t_ast *node);

// code_pieces
char		*getenv_or_blank(const char *name);

//expands dollar sign variables
char		**get_paths(void);
void		clear_tree(t_ast *root);

//AST
t_ast		*ast_constructor(t_list *tokens);
int			ast_split_node(t_ast *ast_node, t_list *tokens,
				t_element *el_to_split);
t_ast		*ast_holder(t_ast *root, int to_free);
void		panic_ast(int error, char *msg);
t_element	*search_and_or(t_list *tokens);
t_element	*search_pipe(t_list *tokens);
t_element	*search_outfile_redir(t_list *tokens);
t_element	*search_infile_redir(t_list *tokens);
t_element	*search_redir(t_list *tokens);

//EXPANSIONS
void		expansions(t_list *tokens);
void		token_expansion(void *p_token);
void		heredoc_expansion(t_token *token);
char		**tokens_to_args(t_list *tokens);
void		asterisk(t_list	*tokens, t_element *el);

// execve
void		execution(t_ast *root);
void		execute(char **tokens);
char		*validate_path(char *exec_name);

//GRAMMAR CHECK
int			grammar_checker(t_list *tokens);
int			is_redirect(int type);
int			is_and_or(int type);
int			redir_and_or_pipe_rule(t_element *el);

//UTILS
int			ft_issymbol(char c);
void		ft_skip_spaces(const char **str);
void		clear_console(void);
void		panic(char *str1, char *str2, char *str3, int err_nb);
int			which_token(const char *str);
t_list		*ft_lstsplit(t_list *lst, t_element *el);
int			last_exit_status(int exit_status);
void		pid_last_exit_status(pid_t pid);
void		ft_clear_list(char ***list);
char		*ft_getenv(const char *name);

//TOKENIZER
t_list		*tokenizer(const char *str);
t_list		*token_list_holder(t_list *tokens, int to_free);
void		free_token(void *p_token);
void		panic_tokenizer(int error, char *msg);
void		add_token(t_list *tokens, const char **start, const char **mover, \
	int token_type);
int			add_special_token(t_list *tokens,
				const char **start, const char **mover, int token_type);
int			quotes_validation(const char *str);
int			parenthesis_validation(const char *str);

//SIGNALS
void		signals_initializer(void);
void		signal_handler(int signal);
int			is_after_prompt(int is_after);
int			on_heredoc(int on_heredoc);

//DEBUGGERS
void		list_printer(t_list *tokens);
void		tree_execs_printer(t_ast *root);

#endif
