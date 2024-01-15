/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and_or_redirs_rule.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:44:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/15 16:48:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_redirect(int	type)
{
	return (type == L_REDIR || type == R_REDIR
		|| type == HEREDOC || type == APPEND);
}

static int is_and_or(int type)
{
	return (type == AND || type == OR);
}

void	redir_and_or_rule(t_element *el)
{
	int		type;
	int		prev_type;

	type = ((t_token *)el->content)->type;
	if (el->prev)
		prev_type = ((t_token *)el->prev->content)->type;
	else
		prev_type = -1;
	if (is_redirect(type) || is_and_or(type))
	{
		if (prev_type == -1)
			ft_putstr_fd("Invalid token begining the line\n", 2); //panic
		else if (!el->next)
			ft_putstr_fd("Invalid token at the end of the line\n", 2); //panic
		else if (is_redirect(prev_type) || is_and_or(prev_type))
			ft_putstr_fd("Invalid syntax\n", 2); //panic
	}
}
