/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nodoulah <nodoulah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 00:55:15 by nodoulah          #+#    #+#             */
/*   Updated: 2025/12/05 00:55:59 by nodoulah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*reader(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes;

	bytes = 1;
	while (!ft_found_line(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(stash);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		stash = str_join(stash, buffer);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*newline;
	char	*pos;

	if (!*stash || !(*stash)[0])
	{
		free(*stash);
		*stash = NULL;
		return (NULL);
	}
	pos = ft_found_line(*stash, '\n');
	if (pos)
	{
		newline = sub_str(*stash, 0, pos - *stash + 1);
		*stash = after_line(*stash);
	}
	else
	{
		newline = sub_str(*stash, 0, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = reader(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
