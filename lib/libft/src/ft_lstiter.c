/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 10:45:27 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/18 19:59:33 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstiter.c
 * @brief Implementation of the ft_lstiter function.
 */

#include "libft.h"

/**
 * @brief Iterates over each element of a linked list and applies a function.
 *
 * This function iterates over each element of the linked list `lst` and applies
 * the given function `f` to the content of each element.
 *
 * @param lst The pointer to the head of the list.
 * @param f   The function to be applied to the content of each element.
 *            If NULL, the function does nothing.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_element	*el;

	if (!lst || !f)
		return ;
	el = lst->first;
	while (el)
	{
		f(el->content);
		el = el->next;
	}
}
