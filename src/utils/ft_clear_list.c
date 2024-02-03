/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:05:25 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/03 09:41:59 by brmoretti        ###   ########.fr       */
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
