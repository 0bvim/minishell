/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:00:13 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/04 12:31:33 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**malloc_error(char **args)
{
	ft_putendl_fd("malloc error", 2);
	if (args)
		ft_clear_list(&args);
	return (NULL);
}

static char	**fill_args(char **args, t_element *el)
{
	int			i;
	t_token		*token;

	i = 0;
	while (el)
	{
		token = el->content;
		args[i] = ft_strdup(token->str);
		if (!args[i++])
			return (malloc_error(args));
		while (!ft_isspace(token->next_char) && el->next)
		{
			el = el->next;
			args[i - 1] = ft_strmerge(args[i - 1], ft_strdup(token->str));
			if (!args[i - 1])
				return (malloc_error(args));
		}
		el = el->next;
	}
	return (args);
}

char	**tokens_to_args(t_list *tokens)
{
	char		**args;
	t_element	*el;

	expansions(tokens);
	args = ft_calloc(tokens->size + 1, sizeof(char *));
	if (!args)
		return (malloc_error(args));
	el = tokens->first;
	return (fill_args(args, el));
}
