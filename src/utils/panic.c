/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   panic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:51:07 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/25 15:43:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	panic(char *str1, char *str2, char *str3, int err_nb)
{
	ft_putstr_fd("minishell:\n", 2);
	ft_putstr_fd(str1, 2);
	ft_putstr_fd(str2, 2);
	ft_putstr_fd(str3, 2);
	if (err_nb)
	{
		ft_putstr_fd("\nError number: ", 2);
		ft_putnbr_fd(err_nb, 2);
	}
	exit(errno);
}
