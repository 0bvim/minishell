/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:51:20 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/15 23:46:06 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

// int main(void)
// {
// 	int	fd = open("aaa", O_RDONLY);
// 	dup2(fd, 0);
// 	close(fd);
// 	char *args[2] = {"./minishell", NULL};
// 	execve("/bin/bash", args, __environ);
// 	return (0);
// }

int main(void)
{
	const char cmd[10] = "echo oi";
	char *args[2] = {"./minishell", NULL};
	int	file = open("/tmp/test", O_RDWR | O_TRUNC | O_CREAT, 0644);
	write(file, cmd, 10);
	close(file);
	file = open("/tmp/test", O_RDONLY);
	dup2(file, 0);
	execve("./minishell", args, __environ);
	return (0);
}