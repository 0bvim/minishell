/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:33:45 by brmoretti         #+#    #+#             */
/*   Updated: 2024/02/14 15:38:38 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_after.c
 * @brief Implementation of the ft_lstadd_before function.
 */

#include "libft.h"

/**
 * Adds a new element `el` before the reference element `ref` in the linked
 * list `lst`.
 * If `el` is NULL, the function returns immediately.
 * If `ref` is the first element of the list, `el` becomes the new first
 * element.
 * The `prev` and `next` pointers of `el` and the reference element are updated
 * accordingly.
 * The size of the list `lst` is incremented by 1.
 *
 * @param lst The linked list to add the element to.
 * @param ref The reference element before which the new element will be added.
 * @param el  The new element to be added.
 */
void	ft_lstadd_before(t_list *lst, t_element *ref, t_element *el)
{
	if (!el)
		return ;
	if (lst->first == ref)
		lst->first = el;
	el->prev = ref->prev;
	if (el->prev)
		el->prev->next = el;
	ref->prev = el;
	el->next = ref;
	lst->size++;
}
