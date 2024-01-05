/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:55:27 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/22 17:17:27 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_front.c
 * @brief Implementation of the ft_lstadd_front function.
 */

#include "libft.h"

/**
 * @brief Adds a new element to the front of a linked list.
 *
 * This function adds the given new element to the front of the linked list.
 *
 * @param lst A pointer to the list.
 * @param el The element to be added to the front of the list.
 */
void	ft_lstadd_front(t_list *lst, t_element *el)
{
	if (!el)
		return ;
	if (lst->first)
	{
		el->next = lst->first;
		lst->first->prev = el;
	}
	else
		el->next = NULL;
	el->prev = NULL;
	lst->first = el;
	if (!lst->last)
		lst->last = el;
	lst->size++;
}
