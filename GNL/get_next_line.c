/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antcamar <antcamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:23:47 by antcamar          #+#    #+#             */
/*   Updated: 2026/01/22 15:55:56 by antcamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clear(char *buf, char *stash)
{
	char	*old_stash;

	old_stash = stash;
	stash = ft_strjoin2(old_stash, buf);
	free(old_stash);
	return (stash);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*tmp;
	int		i;

	if (!*stash || !**stash)
		return (NULL);
	i = 0;
	while ((*stash)[i] && (*stash)[i] != '\n')
		i++;
	if ((*stash)[i] == '\n')
	{
		line = ft_substr(*stash, 0, i + 1);
		tmp = ft_substr(*stash, i + 1, ft_strlen(*stash) - i);
		free(*stash);
		*stash = tmp;
		return (line);
	}
	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

static char	*read_and_accumulate(int fd, char *stash)
{
	char	*buf;
	int		char_read;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	char_read = 1;
	while (char_read > 0)
	{
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read < 0)
		{
			free(stash);
			free(buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		stash = clear(buf, stash);
		if (stash && ft_strchr(stash, '\n'))
			break ;
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_accumulate(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	if (!line && stash)
	{
		free(stash);
		stash = NULL;
	}
	return (line);
}
