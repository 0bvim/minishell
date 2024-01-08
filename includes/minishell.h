/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/01/08 17:56:53 by nivicius         ###   ########.fr       */
=======
/*   Updated: 2024/01/08 19:10:01 by nivicius         ###   ########.fr       */
>>>>>>> develop
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdbool.h>

/* for read line (compile with -lreadline or just -l) */
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/* malloc, free, write, printf, getcwd, chdir, stat, lstat and others */
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
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

/* enum and struct */

enum e_token
{
	TOKEN_ARGUMENT,
	TOKEN_PIPE,
	TOKEN_SEMICOLON,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_L_PAREN,
	TOKEN_R_PAREN,
	TOKEN_QUOTE,
	TOKEN_DOUBLE_QUOTE,
	TOKEN_L_REDIR,
	TOKEN_HEREDOC,
	TOKEN_R_REDIR,
	TOKEN_APPEND,
	TOKEN_NULL
};

// code_pieces
int		create_env_vars_array(char ***env_vars);
//expands dollar sign variables
char	*env_var_value(char *key);

// utils
int		ft_issymbol(char c);
void	clear_console(void);

int		get_token(char **buffer, char *end, char **tk, char **tk_end);
bool	peek(char **buffer, char *end_str, char *toks);

#endif
