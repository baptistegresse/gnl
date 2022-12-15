/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgresse <bgresse@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:57:26 by bgresse           #+#    #+#             */
/*   Updated: 2022/11/25 12:12:00 by bgresse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_file(char *rest, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_bytes;

	read_bytes = 1;
	while (!is_newline(rest, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buffer[read_bytes] = '\0';
		rest = rest_join_buffer(rest, buffer);
	}
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*rest[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rest[fd] = read_file(rest[fd], fd);
	if (!rest[fd])
		return (NULL);
	line = get_before_newline_character(rest[fd]);
	rest[fd] = get_after_newline_character(rest[fd]);
	return (line);
}
