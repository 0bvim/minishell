/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 19:53:32 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/20 01:08:06 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	format_and_print(const char *env_var)
{
	char	*name;
	char	*equal;
	char	*value;
	char	*copy;

	copy = ft_strdup(env_var);
	equal = ft_strchr(copy, '=');
	if (!equal)
		printf("declare -x %s\n", copy);
	else
	{
		*equal = '\0';
		name = copy;
		value = equal + 1;
		printf("declare -x %s=\"%s\"\n", name, value);
	}
	free(copy);
}

static int	print_small(char **env, size_t env_size, unsigned char *printed)
{
	int	small_pos;

	small_pos = -1;
	while (env_size-- > 0)
	{
		if (printed[env_size])
			continue ;
		if (small_pos == -1)
			small_pos = env_size;
		else
		{
			if (ft_strcmp(env[small_pos], env[env_size]) > 0)
				small_pos = env_size;
		}
	}
	if (small_pos != -1)
	{
		format_and_print(env[small_pos]);
		printed[small_pos]++;
		return (1);
	}
	return (0);
}

void	print_environ_sorted(void)
{
	char			**env;
	size_t			size;
	unsigned char	*printed;

	env = environ_holder(NULL, 0);
	size = 0;
	while (env[size])
		size++;
	printed = ft_calloc(size + 1, sizeof(unsigned char));
	while (print_small(env, size, printed))
		;
	free(printed);
}
