/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:21 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/11 22:46:56 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	count_quotes(const char *str, int *single_quotes, int *double_quotes)
{
	char	quote_type;

	*single_quotes = 0;
	*double_quotes = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '"')
		{
			quote_type = *str;
			if (quote_type == '\'')
				(*single_quotes)++;
			else
				(*double_quotes)++;
			str++;
			while (*str && *str != quote_type)
				str++;
			if (*str == '\'')
				(*single_quotes)++;
			else if (*str == '"')
				(*double_quotes)++;
		}
		str++;
	}
}


int	quotes_validation(const char *str)
{
	int		single_quotes;
	int		double_quotes;

	count_quotes(str, &single_quotes, &double_quotes);
	if (single_quotes % 2 || double_quotes % 2)
		return (0);
	return (1);
}


t_list	*treat_quotes(const char *str, t_list *quotes_delimit)
{
	const char		*begin;
	const char		*end;
	t_element	*delimited;
	char		quote_type;

	begin = str;
	end = str;
	while (*end)
	{
		if (*end == '\'' || *end == '"')
		{
			delimited = ft_lstnewelement(ft_strndup(begin, end - begin));
			ft_lstadd_back(quotes_delimit, delimited);
			quote_type = *end;
			begin = end;
			end++;
			while (*end && *end != quote_type)
				end++;
			delimited = ft_lstnewelement(ft_strndup(begin, end - begin + 1));
			ft_lstadd_back(quotes_delimit, delimited);
		}
		end++;
	}
	return (quotes_delimit);
}

t_list	*treat_quotes_init(const char *str)
{
	t_list		*quotes_delimit;
	
	if (!quotes_validation(str))
		return (NULL);
	quotes_delimit = ft_calloc(1, sizeof(t_list));
	if (!quotes_delimit)
		return (NULL); //panic
	quotes_delimit = treat_quotes(str, quotes_delimit);
	return (quotes_delimit);
}
