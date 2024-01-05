/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsecondlast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:03:21 by brmoretti         #+#    #+#             */
/*   Updated: 2023/12/18 20:10:42 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstsecondlast.c
 * @brief Implementation of the ft_lstsecondlast function.
 */

#include "libft.h"

/**
 * @brief Gets the second last element of a linked list.
 *
 * This function returns a pointer to the second last element in the given
 * linked list.
 * If the list is empty, contains only one element, or is uninitialized, the
 * function returns NULL.
 *
 * @param lst A pointer to the linked list.
 * @return A pointer to the second last element, or NULL if conditions
 */
t_element	*ft_lstsecondlast(t_list *lst)
{
	t_element	*el;

	if (!lst || !lst->first || !lst->last || lst->first == lst->last)
		return (NULL);
	el = lst->first;
	while (el->next != lst->last)
		el = el->next;
	return (el);
}
