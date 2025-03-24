/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abdelilah <abdelilah@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:43:30 by abdelilah         #+#    #+#             */
/*   Updated: 2025/03/24 14:44:06 by abdelilah        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char *reading(char *content, char *buffer, int fd, int bytes_read)
{
	char *temp;

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
			return (NULL);
	}
	return (content);
}

char *read_entire_file(char *filename)
{
	char *buffer;
	char *content;
	int bytes_read;
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	content = malloc(1);
	if (!content)
		return (NULL);
	content[0] = '\0';
	bytes_read = 1;
	buffer = NULL;
	return (reading(content, buffer, fd, bytes_read));
}