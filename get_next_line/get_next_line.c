/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muokcan <muokcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:31:38 by muokcan           #+#    #+#             */
/*   Updated: 2024/12/19 16:10:41 by muokcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*new_buffer(char *buffer)
{
	char	*temp;
	size_t	temp_len;
	size_t	i;

	temp_len = 0;
	while (buffer[temp_len] != '\0' && buffer[temp_len] != '\n')
		temp_len++;
	if (buffer[temp_len] == '\n')
		temp_len++;
	if (buffer[temp_len] == '\0')
		return (free_imp(buffer, NULL));
	temp = malloc(((ft_strlen(buffer) - temp_len) + 1) * sizeof(char));
	if (!temp)
		return (free_imp(buffer, NULL));
	i = 0;
	while (buffer[temp_len + i] != '\0')
	{
		temp[i] = buffer[temp_len + i];
		i++;
	}
	temp[i] = 0;
	free (buffer);
	return (temp);
}

static char	*get_line(char *buffer)
{
	char			*temp;
	size_t			temp_len;
	size_t			i;

	if (buffer[0] == 0)
		return (NULL);
	temp_len = 0;
	while (buffer[temp_len] != '\0' && buffer[temp_len] != '\n')
		temp_len++;
	if (buffer[temp_len] == '\n')
		temp_len++;
	temp = malloc((temp_len + 1) * sizeof(char));
	if (!temp)
		return (free_imp(buffer, temp));
	i = 0;
	while (i < temp_len)
	{
		temp[i] = buffer[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

static char	*get_and_merge(int fd, char *buffer)
{
	char			*temp;
	ssize_t			len;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	*temp = '\0';
	if (!temp)
		return (free_imp(buffer, NULL));
	len = 426632;
	while (len > 0 && (!ft_strchr(temp, '\n')))
	{
		len = read(fd, temp, BUFFER_SIZE);
		if (len < 0)
			return (free_imp(buffer, temp));
		temp[len] = '\0';
		buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (free_imp(NULL, temp));
	}
	buffer[ft_strlen(buffer)] = '\0';
	free (temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char		*buffer;
	char			*buffbuff;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = get_and_merge(fd, buffer);
	if (!buffer)
		return (NULL);
	buffbuff = buffer;
	next_line = get_line(buffbuff);
	if (!next_line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = new_buffer(buffer);
	return (next_line);
}
