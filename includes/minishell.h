/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/30 01:12:23 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* for read line (compile with -lreadline or just -l) */
# include "readline/readline.h"

/* malloc, free, write, printf, getcwd, chdir, stat, lstat and others */
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <curses.h>

/* access, open read, close */
# include <fcntl.h>

/* fork, wait family */
# include <sys/types.h>
# include <sys/wait.h>

/* signal family */
#include <signal.h>

/* libft header path */
# include "../lib/libft/includes/libft.h"

# define MAX_NUM_TOKENS 128
/* enum and struct */

typedef enum
{
	TOKEN_COMMAND,
	TOKEN_ARGUMENT,
	TOKEN_AND,
	TOKEN_OR,
	TOKEN_LPAREN,
	TOKEN_RPAREN,
	TOKEN_QUOTE
} TokenType;

/* struct to keep value and type of token */
typedef struct
{
	TokenType	type;
	char		*value;
} Token;

/* struct for command and args */
typedef struct
{
	char	*command;
	char	**arguments;
} Command;

/* struct to handle operators and paretheses, which change the precedence of
 * commands.
 */
typedef struct
{
	Command	*command;
	struct Node	*left;
	struct Node	*right;
} Node;


/* tokenization functions */
Token	*tokenize(char *input);
void	tokenize_and(char *p, Token *tokens, int *num);
void	tokenize_or(char *p, Token *tokens, int *num);
void	tokenize_parentheses(char *p, Token *tokens, int *num);
void	tokenize_quote(char *p, Token *tokens, int *num);
void	tokenize_argument(char *p, Token *tokens, int *num);

#endif
