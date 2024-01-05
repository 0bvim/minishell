/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:19:20 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/18 18:39:53 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsize.c
 * @brief Implementation of the ft_lstsize function.
 */

#include "libft.h"

/**
 * @brief Counts the number of elements in a linked list.
 *
 * This function counts the number of elements in the linked list pointed to
 * by `lst`.
 *
 * @param lst The pointer to the the list.
 * @return The number of elements in the list.
 */
int	ft_lstsize(t_list *lst)
{
	int			i;
	t_element	*el;

	i = 0;
	if (!lst)
		return (i);
	el = lst->first;
	while (el)
	{
		el = el->next;
		i++;
	}
	return (i);
}
