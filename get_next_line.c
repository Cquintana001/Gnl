/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/26 12:49:25 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
void  checkline(char *line2, char *line)
{
    int z;
    int y;
    char *temp;
    
    z=0;
    y=0;
    while (line2[z])
	{
		if (line2[z] == '\n')
		{
			line[y] = line2[z];
			line[y + 1] = '\0';
            z++;

            while(line2[z])
            {
                y = 0;
                temp[y]=line2[z];
                z++;
                y++; 
            }
            y=0;
            z=0;
            while(temp[y])
            {
                line2[z]=temp[y];
                y++;
                z++;
            } 
			 break;
		}
		else
		{
			line[y] = line2[z];
			z++;
			y++;
		}
	}
     
}
char *get_next_line(int fd)
{

	char *line;
	static char line2[BUFFER_SIZE + 1];
	char buf[BUFFER_SIZE + 1];
	int x;
	int y;
	int z;
	ssize_t nr_bytes;
	char *temp;
	
	x = 0;
	y = 0;
	z = 0;
	line = malloc(300);
	 
	 while (line2[z])
	{
		if (line2[z] == '\n')
		{
			line[y] = line2[z];
			 z++;
			 while(line2[z])
			 {
				temp[x] = line2[z];
				x++;
				z++; 
			 }
			 x=0;
			 z=0;
			 while(temp[x])
			 {
				 line2[z]= temp[x];
				 x++;
				 z++;
			 }
			 line2[z+1] = '\0';
			 x = 0;
			 z=0;
			 break;
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
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		buf[nr_bytes] = '\0';
		while (buf[x])
		{
			if (buf[x] == '\n')
			{
				line[y] = '\n';
				 
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
	 
line[y + 1] = '\0';
	printf("Lo que sobra es: %s\n", line2);
	return (line);
}
int main()

{
	int fd;
	ssize_t nr_bytes;
	int x;
	char *result;

	x = 0;

	fd = open("/Users/caquinta/Desktop/pruebagnl.txt", O_RDONLY);
	 while(x<3)
	 {
		result = get_next_line(fd);
		printf("La string devuelta es: %s", result);
		free(result);
		x++;
	 }
	
	close(fd);
	return 0;
}