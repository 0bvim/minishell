/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:45 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/16 18:15:44 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	**malloc_subpatterns_tab(const char *pattern)
{
	size_t	i;
	char	**subpaterns_array;

	i = 2;
	while (*pattern)
	{
		if (*pattern++ == '*')
		{
			while (*pattern == '*')
				pattern++;
			i++;
		}
	}
	subpaterns_array = ft_calloc(i, sizeof(char *));
	return (subpaterns_array);
}

static char	**malloc_subpatterns(const char *pattern, char **subpatterns_array)
{
	size_t			i;
	const char		*start;
	const char		*end;

	start = pattern;
	i = 0;
	while (*start)
	{
		while (*start == '*')
			start++;
		end = start;
		if (*end)
			end++;
		while (*end && *end != '*')
			end++;
		subpatterns_array[i] = ft_strndup(start, end - start);
		if (!subpatterns_array[i++])
		{
			ft_clear_list(&subpatterns_array);
			return (NULL);
		}
		start = end;
	}
	return (subpatterns_array);
}

static int	word_comparison(const char *pattern, const char *word)
{
	char		**subpatterns;
	char		**mover;
	const char	*start;

	subpatterns = malloc_subpatterns_tab(pattern);
	if (!subpatterns)
		return (0);
	subpatterns = malloc_subpatterns(pattern, subpatterns);
	if (!subpatterns)
		return (0);
	start = word;
	mover = subpatterns;
	while (*mover)
	{
		start = ft_strnstr(start, *mover, ft_strlen(start));
		if (!start)
			return (0);
		start += ft_strlen(*(mover++));
	}
	ft_clear_list(&subpatterns);
	return (1);
}

static void	match_insertion(t_list *tokens, t_element *ref, const char *str)
{
	t_element	*el;
	t_token		*token;

	token = ft_calloc(1, sizeof(t_token));
	if (!token)
		return ;
	token->str = ft_strdup(str);
	if (!token->str)
	{
		free (token);
		return ;
	}
	token->type = ARGUMENT;
	token->next_char = ' ';
	el = ft_lstnewelement(token);
	if (!el)
	{
		free (token->str);
		free (token);
		return ;
	}
	ft_lstadd_before(tokens, ref, el);
}

void	asterisk(t_list	*tokens, t_element *el)
{
	DIR				*dir;
	struct dirent	*entry;
	const char		*compare = ((t_token *)el->content)->str;

	dir = opendir(".");
	if (!dir)
		return ;
	entry = readdir(dir);
	while (entry)
	{
		if (*(char *)entry->d_name != '.'
			&& word_comparison(compare, (char *)entry->d_name))
			match_insertion(tokens, el, (char *)entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
}
