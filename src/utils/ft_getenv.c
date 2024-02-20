/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:42:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/20 01:20:07 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv(const char *name)
{
	char	*env_var;
	char	**temp_env;

	temp_env = __environ;
	__environ = environ_holder(NULL, 0);
	env_var = getenv(name);
	__environ = temp_env;
	return (env_var);
}

char	*ft_getenv_or_blank(const char *name)
{
	char	*env_var;

	env_var = ft_getenv(name);
	if (env_var)
		return (env_var);
	return (BLANK);
}
