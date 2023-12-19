/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 10:36:15 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/02 17:29:01 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_end(char const *s1, char const *set, size_t len)
{
	size_t	set_count;
	size_t	end_index;
	int		is_on_set;

	end_index = len;
	while (len)
	{
		set_count = 0;
		is_on_set = 0;
		while (set[set_count] != '\0')
		{
			if (s1[len] == set[set_count])
			{
				end_index--;
				is_on_set = 1;
				break ;
			}
			set_count++;
		}
		if (is_on_set == 0)
			return (end_index);
		len--;
	}
	return (end_index);
}

size_t	ft_start(char const *s1, char const *set)
{
	size_t	set_count;
	size_t	start_index;
	int		is_on_set;

	start_index = 0;
	while (*s1 != '\0')
	{
		set_count = 0;
		is_on_set = 0;
		while (set[set_count] != '\0')
		{
			if (*s1 == set[set_count])
			{
				start_index++;
				is_on_set = 1;
				break ;
			}
			set_count++;
		}
		if (is_on_set == 0)
			return (start_index);
		s1++;
	}
	return (start_index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = ft_start(s1, set);
	end = ft_end(s1, set, ft_strlen(s1) - 1);
	return (ft_substr(s1, start, (end - start + 1)));
}
