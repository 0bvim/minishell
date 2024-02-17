/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_edges.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:34:40 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/16 17:41:09 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	trim_edges(void *content)
{
	t_token	*token;
	char	*tmp;

	token = content;
	if (token->type == QUOTE
		|| token->type == DOUBLE_QUOTE
		|| token->type == BLOCK)
	{
		tmp = ft_strndup(token->str + 1, ft_strlen(token->str) - 2);
		free(token->str);
		token->str = tmp;
	}
}
