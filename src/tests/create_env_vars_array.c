/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_vars_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:58:34 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/15 03:17:24 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(void)
{
	char	**env_vars;
	int		i;
	int		success;

	clear_console();
	success = create_env_vars_array(&env_vars);
	i = -1;
	while (env_vars[++i])
		printf ("%s\n", env_vars[i]);
	printf("\nsuccess = %d\n", success);
	return (EXIT_SUCCESS);
}
