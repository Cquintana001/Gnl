/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/06/01 10:07:43 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

int	checkline(char *array)
{
	int	z;
	int	check;

	z = 0;
	check = 0;
	while (array[z])
	{
		if (array[z] == '\n')
			return (1);
		z++;
	}
	return (-1);
}

/* char	*set_line(char *array)
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
	z++;
	while (array[z])
	{
		temp[x] = array[z];
		z++;
		x++;
	}
	temp[x] = '\0';
	free(array);
	return (temp);
} */

char	*ft_strjoin(char *s1, char *s2)
{
	int		x;
	char	*ptr;
	int		j;

	j = 0;
	x = 0;
	ptr = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	while (s1[x])
	{
		ptr[x] = s1[x];
		x++;
	}
	while (s2[j])
	{
		ptr[x] = s2[j];
		x++;
		j++;
	}
	free(s1);
	ptr[x] = '\0';
	return (ptr);
}

char	*ft_strdup(char *s)
{
	char	*array;
	int		x;

	x = ft_strlen(s);
	array = malloc(x + 1);
	x = 0;
	if (!array)
		return (NULL);
	else
	{
		x = 0;
		while (s[x])
		{
			array[x] = s[x];
			x++;
		}
		array[x] = '\0';
		return (array);
	}
}

/* char	*read_from_fd(int fd, char *buffer)
{
	ssize_t	nr_bytes;
	char	buf1[BUFFER_SIZE + 1];
	char	*temp;
	int		x;

	x = 0;
	while (!buffer || checkline(buffer) == -1)
	{
		nr_bytes = read(fd, buf1, BUFFER_SIZE);
		if (nr_bytes == -1)
			return (NULL);
		if (nr_bytes == 0 && !buffer)
		{
			free(buffer);
			return (NULL);
		}
		else if (nr_bytes == 0)
			return (buffer);
		if (buffer)
		{
			temp = ft_strdup(buffer);
			free(buffer);
		}
		else
			temp = 0;
		buf1[nr_bytes] = '\0';
		if (temp)
		{
			buffer = ft_strjoin(temp, buf1);
			free(temp);
		}
		else
			buffer = ft_strjoin(buf1, "");
		x++;
	}
	return (buffer);
} */
/* char	*get_line_to_return(char *buffer)
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
 */