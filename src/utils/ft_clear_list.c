/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:05:25 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/03 02:28:28 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_clear_list(char **list)
{
	int		i;

	if (!list)
		return ;
	i = 0;
	while (list[i])
	{
		if (list[i] != NULL)
		{
			free(list[i]);
			list[i++] = NULL;
		}
		else
			i++;
	}
	free(list);
	list = NULL;
}
