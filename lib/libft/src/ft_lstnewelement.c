/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnewelement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmoretti <brmoretti@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 10:31:55 by bmoretti          #+#    #+#             */
/*   Updated: 2023/12/22 12:45:44 by brmoretti        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_lstnewelement.c
 * @brief Implementation of the ft_lstnewelement function.
 */

#include "libft.h"

/**
 * @brief Creates a new element for a linked list.
 *
 * This function creates a new element for a linked list with the specified
 * content.
 *
 * @param content The content to be stored in the new element.
 * @return A pointer to the new element, or NULL if memory allocation fails.
 */
t_element	*ft_lstnewelement(void *content)
{
	t_element	*el;

	el = ft_calloc(1, sizeof(t_element));
	if (el == NULL)
		return (NULL);
	el->content = content;
	return (el);
}
