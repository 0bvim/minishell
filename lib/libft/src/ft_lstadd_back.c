/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:29:10 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/22 17:19:05 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstadd_back.c
 * @brief Implementation of the ft_lstadd_back function.
 */

#include "libft.h"

/**
 * @brief Adds a new element to the end of a linked list.
 *
 * This function adds the given new element to the end of the linked list.
 * If the list is empty, the new element becomes the first element.
 *
 * @param lst A pointer to the list.
 * @param el The element to be added to the end of the list.
 */
void	ft_lstadd_back(t_list *lst, t_element *el)
{
	if (!el)
		return ;
	if (lst->last)
		lst->last->next = el;
	el->prev = lst->last;
	el->next = NULL;
	lst->last = el;
	if (!lst->first)
		lst->first = el;
	lst->size++;
}
