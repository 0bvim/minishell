/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 16:16:51 by bmoretti          #+#    #+#             */
/*   Updated: 2024/01/07 18:30:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	which_token_double(char *str)
{
	if (!ft_strncmp(str, "&&", 2))
		return (TOKEN_AND);
	if (!ft_strncmp(str, "||", 2))
		return (TOKEN_OR);
	if (!ft_strncmp(str, "<<", 2))
		return (TOKEN_HEREDOC);
	if (!ft_strncmp(str, ">>", 2))
		return (TOKEN_APPEND);
	return (0);
}

static int	which_token(char *str)
{
	if (which_token_double(str))
		return (which_token_double(str));
	if (!*str)
		return (TOKEN_NULL);
	if (*str == '|')
		return (TOKEN_PIPE);
	if (*str == ';')
		return (TOKEN_SEMICOLON);
	if (*str == '(')
		return (TOKEN_L_PAREN);
	if (*str == ')')
		return (TOKEN_R_PAREN);
	if (*str == '\'')
		return (TOKEN_QUOTE);
	if (*str == '"')
		return (TOKEN_DOUBLE_QUOTE);
	if (*str == '<')
		return (TOKEN_L_REDIR);
	if (*str == '>')
		return (TOKEN_R_REDIR);
	return (TOKEN_ARGUMENT);
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
	if (ret != TOKEN_NULL)
		s++;
	if (ret == TOKEN_AND || ret == TOKEN_OR || ret == TOKEN_HEREDOC)
		s++;
	while (ret == TOKEN_ARGUMENT && s < end && !ft_isspace(*s)
		&& !ft_issymbol(*s))
		s++;
	if (tk_end)
		*tk_end = s;
	return (ret);
}
