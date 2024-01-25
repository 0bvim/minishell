/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 12:51:33 by brmoretti         #+#    #+#             */
/*   Updated: 2024/01/25 15:43:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd(const char **args) {
  char *buffer;
  char *wd;
  size_t chars;

  chars = 1024;
  buffer = ft_calloc(chars, sizeof(char));
  while (buffer && args[0]) {
    wd = getcwd(buffer, sizeof(buffer));
    if (wd) {
      ft_putendl_fd(wd, 1);
      free(buffer);
      return (EXIT_SUCCESS);
    } else {
      free(buffer);
      chars *= 2;
      if (chars > 102400)
        break ;
      buffer = ft_calloc(chars, sizeof(char));
    }
  }
  return (errno);
}
