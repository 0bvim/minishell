/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asterisk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:48:45 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/19 16:14:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	int	compare_end(const char *word, const char *subpattern)
{
	char	*end;
	size_t	lens[2];

	lens[0] = ft_strlen(word);
	lens[1] = ft_strlen(subpattern);
	if (lens[1] > lens[0])
		return (0);
	end = (char *)word;
	end += lens[0] - lens[1];
	if (!ft_strcmp(end, subpattern))
		return (1);
	return (0);
}

static int	word_comparison(const char *word,
	const char **subpatterns, int comp_type)
{
	const char	*start;
	int			begin_ok;

	start = word;
	begin_ok = 0;
	while (*subpatterns)
	{
		start = ft_strnstr(start, *subpatterns, ft_strlen(start));
		if (!start)
			return (0);
		if (!begin_ok
			&& ((comp_type == M_NONE || comp_type == M_END)
				|| start == word))
			begin_ok = 1;
		if (begin_ok)
			start += ft_strlen(*(subpatterns++));
		else
			return (0);
	}
	if (comp_type >= M_END)
		return(compare_end(word, *(--subpatterns)));
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

void	define_subpatterns(char	***subpatterns,
	const char *pattern, int *comp_type)
{
	*subpatterns = ft_split(pattern, '*');
	*comp_type = M_NONE;
	if (pattern[0] != '*')
		*comp_type += M_START;
	if (pattern[ft_strlen(pattern) - 1] != '*')
		*comp_type += M_END;
}

void	asterisk(t_list	*tokens, t_element *el)
{
	DIR				*dir;
	struct dirent	*entry;
	const char		*compare = ((t_token *)el->content)->str;
	int				comp_type;
	char			**subpaterns;

	dir = opendir(".");
	if (!dir)
		return ;
	define_subpatterns(&subpaterns, compare, &comp_type);
	if (!subpaterns)
		return ;
	entry = readdir(dir);
	while (entry)
	{
		if (*(char *)entry->d_name != '.'
			&& word_comparison(((const char *)entry->d_name),
				(const char **)subpaterns, comp_type))
			match_insertion(tokens, el, (char *)entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
	ft_clear_list(&subpaterns);
}
