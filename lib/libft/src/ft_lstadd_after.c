/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:09:02 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/14 15:39:41 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_after.c
 * @brief Implementation of the ft_lstadd_after function.
 */

#include "libft.h"

/**
 * Adds a new element `el` after the reference element `ref` in the linked
 * list `lst`.
 * If `el` is NULL, the function returns immediately.
 * If `ref` is the last element of the list, `el` becomes the new last
 * element.
 * The `prev` and `next` pointers of `el` and the reference element are updated
 * accordingly.
 * The size of the list `lst` is incremented by 1.
 *
 * @param lst The linked list to add the element to.
 * @param ref The reference element after which the new element will be added.
 * @param el  The new element to be added.
 */
void	ft_lstadd_after(t_list *lst, t_element *ref, t_element *el)
{
	if (!el)
		return ;
	if (lst->last == ref)
		lst->last = el;
	el->next = ref->next;
	if (el->next)
		el->next->prev = el;
	ref->next = el;
	el->prev = ref;
	lst->size++;
}
