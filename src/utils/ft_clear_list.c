/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:05:25 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 02:01:35 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_list(char ***list)
{
	int		i;

	if (!*list)
		return ;
	i = 0;
	while ((*list)[i])
	{
		free((*list)[i]);
		(*list)[i++] = NULL;
	}
	free(*list);
	*list = NULL;
}

void	close_tmp(const int *tmp)
{
	close(tmp[0]);
	close(tmp[1]);
}
