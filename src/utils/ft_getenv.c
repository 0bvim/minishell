/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:42:26 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/02 11:50:16 by vde-frei         ###   ########.fr       */
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
