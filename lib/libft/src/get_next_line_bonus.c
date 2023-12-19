/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:32:39 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/23 14:46:41 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_file_info	file[1024];

	if ((!fd || fd > 1024 || fd < 0) && fd != 0)
		return (NULL);
	if (file[fd].pos >= file[fd].read || file[fd].pos == 0)
	{
		file[fd].pos = 0;
		while (file[fd].pos < BUFFER_SIZE)
			file[fd].buffer[file[fd].pos++] = '\0';
		file[fd].pos = 0;
		file[fd].string = NULL;
		file[fd].len = 0;
		file[fd].fd = fd;
		file[fd].read = read(fd, file[fd].buffer, BUFFER_SIZE);
		if (file[fd].read == -1)
			return (free_str(file[fd].string));
	}
	if (file[fd].read <= 0 || file[fd].buffer[file[fd].pos] == '\0')
	{
		free_str(file->string);
		return (NULL);
	}
	if (file[fd].read < 0 && file[fd].string)
		return (free_str(file->string));
	return (ft_read_line(&file[fd]));
}

char	*ft_read_line(t_file_info *file)
{
	file->len = 0;
	while (file->read > 0)
	{
		link_letter(&file->string, get_letter(*(file->buffer + file->pos)));
		if (*(file->buffer + file->pos) == '\n'
			|| *(file->buffer + file->pos) == '\0')
			break ;
		file->pos++;
		file->len++;
		if (file->pos >= file->read)
		{
			file->pos = 0;
			file->read = read (file->fd, file->buffer, BUFFER_SIZE);
			if (file->read == -1)
				return (free_str(file->string));
		}
	}
	file->pos++;
	file->len++;
	return (ft_build_line(file));
}

char	*ft_build_line(t_file_info *file)
{
	t_char	*next;
	char	*line;
	int		count;

	line = (char *)malloc((file->len + 1) * sizeof(char));
	if (!(line || file->fd) && file->fd != 0)
		return (NULL);
	count = 0;
	next = NULL;
	while (file->string)
	{
		next = file->string->next;
		line[count] = file->string->single_char;
		free(file->string);
		file->string = next;
		count++;
	}
	line[count] = '\0';
	return (line);
}
