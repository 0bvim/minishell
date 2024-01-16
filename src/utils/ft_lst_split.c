/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:10:46 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/16 10:41:37 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/libft/include/libft.h"

/**
 * Splits a linked list into two at the specified element.
 *
 * @param lst The original linked list.
 * @param el The element at which to split the list.
 * @return A new linked list containing the elements after the specified element,
 *         or NULL if either the original list or the element is NULL.
 */
t_list	*ft_lstsplit(t_list *lst, t_element *el)
{
	t_list		*new_lst;
	t_element	*tmp_el;

	if (!lst || !el)
		return (NULL);
	new_lst = ft_calloc(1, sizeof(t_list));
	if (!new_lst)
		return (NULL);
	tmp_el = lst->last;
	while (tmp_el && tmp_el != el)
	{
		ft_lstadd_front(new_lst, ft_lstpop(lst, -1));
		tmp_el = lst->last;
	}
	return (new_lst);
}
