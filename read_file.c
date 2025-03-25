/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 05:15:58 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/25 15:34:56 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*reading(char *content, int fd)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (free(content), NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(content), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(content, buffer);
		free(buffer);
		free(content);
		content = temp;
		if (!content)
			return (close(fd), NULL);
	}
	close(fd);
	return (content);
}

char	*read_entire_file(char *filename)
{
	char	*content;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = malloc(1);
	if (!content)
		return (NULL);
	content[0] = '\0';
	return (reading(content, fd));
}
