/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 18:42:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/08 18:43:47 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	main(void)
{
	// char	*input;
	char	*str;

	clear_console();
	str = env_var_value("LSCOLORS");
	printf("-%s-\n", str);
	str = env_var_value("INVALID");
	printf("-%s-\n", str);
	return (EXIT_SUCCESS);
}