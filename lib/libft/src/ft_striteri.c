/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 18:02:51 by bmoretti          #+#    #+#             */
/*   Updated: 2023/11/14 10:46:17 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
 * @brief Implementation of the ft_striteri function.
 */

/**
 * @brief Applies a function to each character of a string, passing its index
 *        as well.
 *
 * This function applies the function 'f' to each character of the string 's',
 * passing the index of the character as the first argument to the function.
 *
 * @param s A pointer to the null-terminated string.
 * @param f The function to be applied to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
