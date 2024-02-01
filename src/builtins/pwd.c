/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:51:33 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/01 16:35:43 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*malloc_pwd(void)
{
	char	*buffer;
	char	*wd;
	size_t	chars;

	chars = 1024;
	buffer = ft_calloc(chars, sizeof(char));
	while (buffer)
	{
		wd = getcwd(buffer, chars);
		if (wd)
			return (wd);
		else
		{
			free(buffer);
			chars *= 2;
			if (chars > 102400)
				break ;
			buffer = ft_calloc(chars, sizeof(char));
		}
	}
	return (NULL);
}

int	pwd(const char **args)
{
	char	*wd;

	(void)args;
	wd = malloc_pwd();
	if (!wd)
		return (EXIT_FAILURE);
	ft_putendl_fd(wd, STDOUT_FILENO);
	free (wd);
	return (EXIT_SUCCESS);
}
