/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_quotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:28:06 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/03 18:17:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	trim_quotes(char **str)
{
	char	*tmp;
	char	*tmp_2;

	tmp = *str;
	tmp_2 = ft_strndup(tmp + 1, ft_strlen(tmp) - 2);
	free(tmp);
	*str = tmp_2;
}
