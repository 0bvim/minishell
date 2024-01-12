/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:16:51 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/12 18:38:56 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	which_token_double(char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (AND);
	if (!ft_strncmp(str, "||", 2))
		return (OR);
	if (!ft_strncmp(str, "<<", 2))
		return (HEREDOC);
	if (!ft_strncmp(str, ">>", 2))
		return (APPEND);
	return (0);
}

static int	which_token(char *str)
{
	if (which_token_double(str))
		return (which_token_double(str));
	if (!*str)
		return (TOKEN_NULL);
	if (*str == '|')
		return (PIPE);
	if (*str == '(')
		return (L_PAREN);
	if (*str == ')')
		return (R_PAREN);
	if (*str == '\'')
		return (QUOTE);
	if (*str == '"')
		return (DOUBLE_QUOTE);
	if (*str == '<')
		return (L_REDIR);
	if (*str == '>')
		return (R_REDIR);
	return (ARGUMENT);
}

int	get_token(char **buffer, char *end, char **tk, char **tk_end)
{
	char	*s;
	int		ret;

	s = *buffer;
	while (s < end && ft_isspace(*s))
		s++;
	if (tk)
		*tk = s;
	ret = which_token(s);
	if (ret != 0x0)
		s++;
	if (ret == AND || ret == OR || ret == HEREDOC)
		s++;
	while (ret == ARGUMENT && s < end && !ft_isspace(*s)
		&& !ft_issymbol(*s))
		s++;
	if (tk_end)
		*tk_end = s;
	return (ret);
}
