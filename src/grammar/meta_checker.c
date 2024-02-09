/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:13:42 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/09 11:10:03 by nivicius         ###   ########.fr       */
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
