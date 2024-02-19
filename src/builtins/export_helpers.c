/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 19:04:25 by bmoretti          #+#    #+#             */
/*   Updated: 2024/02/19 19:17:03 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*key_name(const char *key_value)
{
	char	*equal_sign;

	equal_sign = ft_strchr(key_value, '=');
	if (!equal_sign)
		return (ft_strdup(key_value));
	else
		return (ft_strndup(key_value, equal_sign - key_value));
}

int	is_valid_identifier(char *str)
{
	if (*str != '=' && !ft_isdigit(*str))
	{
		while (*str && *str != '=' && (ft_isalnum(*str) || *str == '_'))
			str++;
		if (*str == '=' || !*str)
			return (1);
	}
	ft_putendl_fd("minishell: export: not a valid identifier", 2);
	last_exit_status(1);
	return (0);
}
