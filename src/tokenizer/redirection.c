/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:50:38 by vde-frei          #+#    #+#             */
/*   Updated: 2024/01/04 18:34:29 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	tokenize_redirection(char **p, t_token **tokens, int *num)
{
	if (ft_strchr("><>><<", **p))
	{
		(*tokens)[*num].type = TOKEN_REDIRECT;
		(*tokens)[*num].value = *p;
		(*num)++;
		*p += 1;
	}
}
