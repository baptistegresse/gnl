/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:57:57 by bgresse           #+#    #+#             */
/*   Updated: 2022/11/25 12:12:03 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 666
# endif

char	*get_next_line(int fd);
char	*read_file(char *rest, int fd);

char	*rest_join_buffer(char *rest, char *buffer);
size_t	ft_strlen(char *string);
int		is_newline(char *rest, char newline);

char	*get_before_newline_character(char *rest);
char	*get_after_newline_character(char *rest);

#endif