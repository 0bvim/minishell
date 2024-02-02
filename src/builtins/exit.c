/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:19:57 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/02 11:52:51 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	builtin_exit(char **args)
{
	ft_clear_list(&args);
	ast_holder(NULL, 1);
	environ_holder(NULL, 1);
	ft_putendl_fd("exit", 1);
	exit(EXIT_SUCCESS);
}
