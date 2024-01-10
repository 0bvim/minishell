/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/10 15:42:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

/* for read line (compile with -lreadline or just -l) */
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>

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

# define SYMBOLS "&|<>;()'\""
# define BLANK ""

# include "cmds.h"
# include "parsers.h"

/* enum and struct */

enum	e_token
{
	ARGUMENT,
	PIPE,
	SEMICOLON,
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
	EXEC
};

// code_pieces
int		create_env_vars_array(char ***env_vars);
//expands dollar sign variables
char	*env_var_value(char *key);

// utils
int		ft_issymbol(char c);
void	clear_console(void);
void	panic(char *str1, char *str2, char *str3, int err_nb);

int		get_token(char **buffer, char *end, char **tk, char **tk_end);
bool	peek(char **buffer, char *end_str, char *toks);

//NEW_TOKENIZER
typedef struct s_branch
{
	int					type;
	char				*str;
	struct s_branch		*parent;
	struct s_branch		*left;
	struct s_branch		*right;
}	t_branch;

t_branch	*tokenizer(char *line);
void		print_tree(t_branch *root);
void		free_tree(t_branch *root);

#endif
