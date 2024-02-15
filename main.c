/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:51:20 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/15 01:09:35 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int	fd = open("testes_minishell.txt", O_RDONLY);
	dup2(fd, 0);
	close(fd);
	char *args[2] = {"./minishell", NULL};
	execve("/bin/bash", args, __environ);
	return (0);
}