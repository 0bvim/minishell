/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/02 18:24:12 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* for read line (compile with -lreadline or just -l) */
# include <readline/readline.h>
# include <readline/history.h>

/* malloc, free, write, printf, getcwd, chdir, stat, lstat and others */
# include <stdio.h>
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
# include "../lib/libft/includes/libft.h"

# define MAX_NUM_TOKENS 128
# define clear() printf("\033[H\033[J")

/* enum and struct */

typedef enum e_token_type
{
	TOKEN_COMMAND,
	TOKEN_ARGUMENT,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_QUOTE
}	t_token_type;

/* struct to keep value and type of token */
typedef struct s_Token
{
	t_token_type	type;
	char			*value;
}	t_token;

/* struct for command and args */
typedef struct s_command
{
	char	*command;
	char	**arguments;
}	t_command;

/* struct to handle operators and paretheses, which change the precedence of
 * commands.
 */
typedef struct s_node
{
	t_command	*command;
	struct Node	*left;
	struct Node	*right;
}	t_node;

/* tokenization functions */
t_token	*tokenize(char *input);
void	tokenize_and(char **p, t_token **tokens, int *num);
void	tokenize_or(char **p, t_token **tokens, int *num);
void	tokenize_parentheses(char **p, t_token **tokens, int *num);
void	tokenize_quote(char **p, t_token **tokens, int *num);
void	tokenize_argument(char **p, t_token **tokens, int *num);

#endif
