/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 11:48:52 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/18 20:12:09 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstmap.c
 * @brief Implementation of the ft_lstmap function.
 */

#include "libft.h"

/**
 * @brief Applies a function to each element of a linked list and creates a
 * new list.
 *
 * This function applies the function `f` to each element of the linked
 * list `lst` and creates a new list with the results. The `del` function is
 * used to delete the content of an element if an allocation failure occurs.
 *
 * @param lst The pointer to the head of the list.
 * @param f   The function to be applied to the content of each element.
 * @param del The function to delete the content of an element in case of
 * allocation failure.
 * @return A pointer to the new list, or NULL if an allocation failure occurs.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_lst;
	t_element	*el;
	t_element	*new_el;

	if (!lst || !lst->first || !f)
		return (NULL);
	new_lst = ft_calloc(1, sizeof(t_list));
	el = lst->first;
	while (el)
	{
		new_el = ft_lstnewelement(f(el->content));
		if (!new_el)
		{
			ft_lstclear(new_lst, del);
			return (NULL);
		}
		el = el->next;
		ft_lstadd_back(new_lst, new_el);
	}
	return (new_lst);
}
