/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/25 12:26:50 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>

char *get_next_line(int fd)
{
     
    char static *line;
	char static *line2;
	char buf[42];
	int x;
	int y;
	int z;
    ssize_t nr_bytes;
     
    x = 0;
	y = 0; 
	z = 0;
    line =  malloc(42);
	line2 = malloc(42);
	 
     nr_bytes = read(fd, buf, 42);
		while(buf[x])
		{
			if(buf[x] == '\n')
			{
				line[y] = '\n';
				line[y+1] = '\0';
				x++;
				while(buf[x])
				{
					line2[z] = buf[x];
					x++;
					z++;
				}
				line2[z]= '\0';
				x = 0;
				printf("La string devuelta es: %s\n", line);
				printf("Lo que sobra es: %s\n", line2);
				return(line);
			}
			else
			line[y] = buf[x];
			x++;
			y++;
		}
		
           printf("La string devuelta es: %s", line);
		     
        close(fd);
         
             
             
    return(line);     
    
 
}
int main()

{
    int fd;
    ssize_t nr_bytes;
	 
	
    fd = open("/Users/caquinta/Desktop/pruebagnl.txt", O_RDONLY); 
	 
	 get_next_line(fd);
	    
 	 
 
    return 0;
}