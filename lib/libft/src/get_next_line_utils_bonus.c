/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:40:15 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/22 20:30:20 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_char	*get_letter(char letter)
{
	t_char	*set_char;

	set_char = (t_char *)malloc(sizeof(t_char));
	set_char->single_char = letter;
	set_char->next = NULL;
	return (set_char);
}

void	link_letter(t_char **head, t_char *new_letter)
{
	t_char	*aux;

	if (!new_letter)
		return ;
	if (!*head)
	{
		*head = new_letter;
		return ;
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	aux->next = new_letter;
}

char	*free_str(t_char *string)
{
	t_char	*temp;

	temp = string;
	while (temp)
	{
		temp = temp->next;
		free(string);
		string = temp;
	}
	temp = NULL;
	return (NULL);
}
