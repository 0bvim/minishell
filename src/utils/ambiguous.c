/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:54:26 by vde-frei          #+#    #+#             */
/*   Updated: 2024/06/23 15:57:51 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ambiguous_error(void)
{
	ft_putendl_fd("Error: ambigous redirect", 2);
	last_exit_status(1);
	return (0);
}
