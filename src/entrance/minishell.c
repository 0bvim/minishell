/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 21:19:43 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/28 11:59:16 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc __attribute__((unused)), char **argv __attribute__((unused)),
		char **envp)
{
	printf("Hello I'm your own shell!\n");
	return (EXIT_SUCCESS);
}
