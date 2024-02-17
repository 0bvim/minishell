/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:13:42 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 18:50:12 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_redirect(int type)
{
	return (type == L_REDIR || type == R_REDIR
		|| type == HEREDOC || type == APPEND);
}

int	is_and_or(int type)
{
	return (type == AND || type == OR);
}

int	is_quotes(int type)
{
	return (type == QUOTE || type == DOUBLE_QUOTE);
}

int	is_metacharacter(int type)
{
	return (is_redirect(type) || is_and_or(type) || type == PIPE);
}
