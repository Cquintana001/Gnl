/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/01 13:47:18 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "get_next_line_bonus.h"
#include <limits.h>
#include <time.h>

char	*read_from_fd(int fd, char *buffer)
{
	ssize_t	nr_bytes;
	char	buf1[BUFFER_SIZE + 1];
	char	*temp;

	while (!buffer || checkline(buffer) == -1)
	{
		nr_bytes = read(fd, buf1, BUFFER_SIZE);
		if (nr_bytes <= 0 && !buffer)
		{
			free(buffer);
			return (NULL);
		}
		else if (nr_bytes == 0)
			return (buffer);
		buf1[nr_bytes] = '\0';
		if (buffer)
		{
			temp = buffer;
			buffer = ft_strjoin(buffer, buf1);
		}
		else
			buffer = ft_strdup(buf1);
	}
	return (buffer);
}

char	*get_line_to_return(char *buffer)
{
	int		z;
	int		x;
	char	*line;

	x = 0;
	z = 0;
	while (buffer[z])
	{
		if (buffer[z] == '\n')
		{
			z++;
			break ;
		}
		z++;
	}
	line = malloc(z + 1);
	while (x < z)
	{
		line[x] = buffer[x];
		x++;
	}
	line[x] = '\0';
	return (line);
}

char	*set_line(char *array)
{
	int		z;
	int		x;
	char	*temp;

	z = 0;
	while (array[z] != '\n' && array[z])
		z++;
	x = ft_strlen(array) - z;
	if (x > 1)
		temp = malloc(x);
	else
	{
		free(array);
		return (0);
	}
	x = 0;
	while (array[++z])
	{
		temp[x] = array[z];
		x++;
	}
	temp[x] = '\0';
	free(array);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*aux;
	static char	*line2[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = line2[fd];
	aux = read_from_fd(fd, aux);
	if (aux == NULL)
	{
		free(aux);
		return (NULL);
	}
	else
	{
		line = get_line_to_return(aux);
		line2[fd] = set_line(aux);
		return (line);
	}
}
