/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_to_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nivicius <nivicius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:00:13 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/17 17:24:57 by nivicius         ###   ########.fr       */
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
		if (token->str[0])
		{
			args[i] = ft_strdup(token->str);
			if (!args[i++])
				return (malloc_error(args));
			while (!ft_isspace(token->next_char) && el->next)
			{
				el = el->next;
				token = el->content;
				args[i - 1] = ft_strmerge(args[i - 1], ft_strdup(token->str));
				if (!args[i - 1])
					return (malloc_error(args));
			}
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
