/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:17:48 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/01 13:13:00 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	environ_initializer(void)
{
	char		**new_environ;
	int			i;

	i = 0;
	while (__environ[i])
		i++;
	new_environ = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (__environ[i])
	{
		new_environ[i] = ft_strdup(__environ[i]);
		if (!new_environ[i++])
		{
			ft_clear_list(&new_environ);
			exit(EXIT_FAILURE);
		}
	}
	new_environ[i] = NULL;
	environ_holder(new_environ, 0);
}

char	**environ_holder(char **new_environ, int to_free)
{
	static char	**environ_holder;

	if (new_environ)
		environ_holder = new_environ;
	if (environ_holder && to_free)
	{
		ft_clear_list(&environ_holder);
		environ_holder = NULL;
	}
	return (environ_holder);	
}

