/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:32:26 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/22 16:34:21 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstdelone.c
 * @brief Implementation of the ft_lstdelone function.
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
 * @brief Deletes a single element from a linked list.
 *
 * This function deletes the specified element `lst` from the linked list.
 * The content of the element is deleted using the provided deletion function
 * `del`.
 *
 * @param lst The element to be deleted.
 * @param del The function used to delete the content of the element.
 *            If NULL, the content will not be deleted.
 */
void	ft_lstdelone(t_list *lst, t_element *el, void (*del)(void*))
{
	if (!el)
		return ;
	if (lst)
	{
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
	}
	del(el->content);
	free (el);
	lst->size--;
}
