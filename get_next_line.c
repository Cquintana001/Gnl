/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/25 14:38:17 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>

char *get_next_line(int fd)
{

	char *line;
	char static *line2;
	char buf[42];
	int x;
	int y;
	int z;
	ssize_t nr_bytes;

	y = 0;
	z = 0;
	line = malloc(300);
	line2 = malloc(300);
	while(line2[z])
	{
		if(line[z] == '\n')
		{	
			line[y]= line[z];
			line[y +1] ='\0';
			return(line);
		}
		else
		{
		line[y] = line2[z];
		z++;
		y++;
		}
	}
	while (line[y] != '\n')
	{
		x = 0;
		nr_bytes = read(fd, buf, 42);
		buf[nr_bytes] = '\0';
		while (buf[x])
		{
			if (buf[x] == '\n')
			{
				line[y] = '\n';
				line[y + 1] = '\0';
				x++;
				while (buf[x])
				{
					line2[z] = buf[x];
					x++;
					z++;
				}
				line2[z] = '\0';
				break;
				 
			}
			else
			{
				line[y] = buf[x];
				x++;
				y++;
			}
			 
		}
	}
	close(fd);
	 
	printf("Lo que sobra es: %s\n", line2);
	return (line);
}
int main()

{
	int fd;
	ssize_t nr_bytes;
	int x;

	x = 0;

	fd = open("/Users/caquinta/Desktop/pruebagnl.txt", O_RDONLY);
	 while(x<2)
	 {
	printf("La string devuelta es: %s", get_next_line(fd));
	 x++;
	 }
	return 0;
}