/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:40:40 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/22 16:33:33 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstpop.c
 * @brief Implementation of the ft_lstpop function.
 */

#include "libft.h"

static void	ft_el_is_first(t_list *lst, t_element *el)
{
	lst->first = el->next;
	if (lst->first)
		lst->first->prev = NULL;
}

static void	ft_el_is_last(t_list *lst, t_element *el)
{
	lst->last = el->prev;
	if (lst->last)
		lst->last->next = NULL;
}

/**
 * Removes and returns an element from a linked list at the specified index.
 *
 * @param lst The linked list from which to remove the element.
 * @param index The index of the element to be removed.
 * @return The removed element, or NULL if the index is out of range.
 */
t_element	*ft_lstpop(t_list *lst, int index)
{
	t_element	*el;

	el = ft_lstpickel(lst, index);
	if (!el)
		return (NULL);
	if (el != lst->first && el != lst->last)
	{
		el->prev->next = el->next;
		el->next->prev = el->prev;
	}
	else
	{
		if (el == lst->first)
			ft_el_is_first(lst, el);
		if (el == lst->last)
			ft_el_is_last(lst, el);
	}
	el->next = NULL;
	el->prev = NULL;
	lst->size--;
	return (el);
}
