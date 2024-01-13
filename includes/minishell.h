/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/12 20:55:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <assert.h>

/* for read line (compile with -lreadline or just -l) */
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>

/* malloc, free, write, printf, getcwd, chdir, stat, lstat and others */
# include <dirent.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
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

# define SYMBOLS "&|<>()'\""
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
	EXEC
};

// code_pieces
int		create_env_vars_array(char ***env_vars);
//expands dollar sign variables
char	*env_var_value(char *key);

// utils
int		ft_issymbol(char c);
void	ft_skip_spaces(const char **str);
void	clear_console(void);
void	panic(char *str1, char *str2, char *str3, int err_nb);

t_list	*tokenizer(const char *str);

#endif
