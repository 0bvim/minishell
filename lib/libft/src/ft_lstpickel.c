/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpickel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:32:18 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/22 16:04:52 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstpickel.c
 * @brief Implementation of the ft_lstpickel function.
 */

#include "libft.h"

/**
 * Returns an element from a linked list at the specified index.
 *
 * @param lst The linked list from which to return the element.
 * @param index The index of the element to be returned.
 * 			If negative, the element is returned from the end of the list.
 * 			If the absolute value of the index is greater than the size of the
 * 			list, NULL is returned.
 * @return The element at the specified index, or NULL if the index is out of
 *         range.
 */
t_element	*ft_lstpickel(t_list *lst, int index)
{
	t_element	*el;

	if ((!lst) || (index < 0 && - index > (int)lst->size)
		|| (index >= 0 && index + 1 > (int)lst->size))
		return (NULL);
	if (index < 0)
	{
		el = lst->last;
		while (++index)
			el = el->prev;
	}
	else
	{
		el = lst->first;
		while (index--)
			el = el->next;
	}
	return (el);
}
