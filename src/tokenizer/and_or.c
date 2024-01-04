/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:18:23 by vde-frei          #+#    #+#             */
/*   Updated: 2023/12/30 23:56:02 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void tokenize_and(char **p, t_token **tokens, int *num)
{
	if (**p == '&' && *(*p + 1) == '&')
	{
		(*tokens)[*num].type = TOKEN_AND;
		(*tokens)[*num].value = "&&";
		(*num)++;
		*p += 2;
	}
}

void tokenize_or(char **p, t_token **tokens, int *num)
{
	if (**p == '|' && *(*p + 1) == '|')
	{
		(*tokens)[*num].type = TOKEN_OR;
		(*tokens)[*num].value = "||";
		(*num)++;
		*p += 2;
	}
}
