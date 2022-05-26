/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxfunction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 11:10:59 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/26 16:16:47 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>

int checkline(char *array) // return index of any '\n' in the string, otherwise return 0
{
    int z;
    int check;

    z = 0;
    check = 0;
    while (array[z])
    {
        if (array[z] == '\n')
            return (z);
        z++;
    }
    return (0);
}

void setline(char *array, int index) //trim the string until reach the index
{
    int z;
    char *temp;

    z = 0;
    index++;
    while (array[index])
    {
        temp[z] = array[index];
        z++;
        index++;
    }
    z=0;
    while(temp[z])
    {
        array[z] = temp[z];
        z++;
    }
    array[z] = '\0';
}
void cpline(char *temp, char *array, int index)
{
    int x;
     
    x=0;
    while(x<=index)
    {
        temp[x] = array[x];
        x++;
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
    int index;
	ssize_t nr_bytes;
	char *temp;
	
	x = 0;
	y = 0;
	z = 0;
	line = malloc(300);
    index = checkline(line2);
    
	if(index != 0)      
	 {    
         cpline(line, line2, index);
         setline(line2, index);
         return(line);
    }
    while(line2[x])
    {
        line[y] = line2[x];
        x++;
        y++;
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
	//printf("Lo que sobra es: %s\n", line2);
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