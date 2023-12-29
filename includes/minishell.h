/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:55:27 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/29 02:19:14 by nivicius         ###   ########.fr       */
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

#endif
