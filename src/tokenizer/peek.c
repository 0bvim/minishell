/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 02:18:47 by nivicius          #+#    #+#             */
/*   Updated: 2024/01/08 17:56:08 by nivicius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	peek(char **buffer, char *end_str, char *toks)
{
	char	*start;

	start = *buffer;
	while (start < end_str && ft_isspace(*start))
		start++;
	*buffer = start;
	return (*start && ft_strchr(toks, *start));
}
