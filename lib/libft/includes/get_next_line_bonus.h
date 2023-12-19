/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-frei <vde-frei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 13:17:45 by vde-frei          #+#    #+#             */
/*   Updated: 2023/08/23 14:46:21 by vde-frei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

/* libs */
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

/* buffer to read */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif /* BUFFER_SIZE */

/* typedef and struct declaration */
/**
 * @brief Linked list to store char by char.
 * @param char The char of each struct.
 * @param *next The pointer to next struct (list / node).
 */
typedef struct s_char	t_char;
struct s_char
{
	char	single_char;
	t_char	*next;
};

/**
 * @brief Linked list to store fd infos.
 * @param pos Position to read fd content.
 * @param read Receive C function 'read' (man 3 read for more info).
 * @param len Lenght of string until '\n' or '\0'.
 * @param fd Is the file descriptor (given param of GNL function).
 * @param buffer[BUFFER_SIZE] Is the buffer that.
 * keep the same value of defined BUFFER_SIZE.
 * @param t_char *string Is a struct to store string char
 * by char until '\n' or '\0'.
 */
typedef struct s_file_info
{
	int				pos;
	int				read;
	int				len;
	int				fd;
	char			buffer[BUFFER_SIZE];
	t_char			*string;
}t_file_info;

/**
 * @brief This function read a buffer and return next line.
 * until the content end.
 * @param fd Number of file descriptor to read.
 * @return char Return line by line in fd given as a parameter and
 * when content ends, return NULL.
 */
char	*get_next_line(int fd);

/**
 * @brief This function create a new node.
 * @param char Need of a character to set as a value.
 * @return t_char A node with value and a NULL pointer to the next node.
 */
t_char	*get_letter(char letter);

/**
 * @brief This function get a new node and
 * put it at the end of linked list.
 * @param t_char Need of a struct address.
 * @param head Need of a pointer to a struct.
 * @return void This function only change content.
 */
void	link_letter(t_char **head, t_char *new_letter);

/**
 * @brief This function get content from file->buffer and
 * read file content until new_line or end of string.
 * and store it in t_char *string.
 * @param t_file_info A pointer do a struct.
 * @return char * A string to get_next_line function.
 */
char	*ft_read_line(t_file_info *file);

/**
 * @brief This function concatenate the lines that were read
 * with '\0' (null byte). And 'free' nodes which memory was
 * allocated.
 * @param t_file_info *file Is the struct that contains all
 * variables to be manipulated.
 * @return String to be returned with ('\n') and
 * null byte ('\0') at the end of string.
 */
char	*ft_build_line(t_file_info *file);

/**
 * @brief Receive the HEAD node and roam node by node
 * and free memory that was allocated.
 * @param t_char *string First node of the linked list.
 * @return Clean linked list nodes.
 */
char	*free_str(t_char *string);
#endif /* GET_NEXT_LINE */
