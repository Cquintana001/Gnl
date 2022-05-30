/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/30 17:44:09 by caquinta         ###   ########.fr       */
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
int checkline(char *array)  
{
    int z;
    int check;

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
char  *set_line(char *array)  
{
    int z;
    int x;
    char *temp;

    z = 0;
     
    while (array[z]!='\n' && array[z])       
        z++;
    x = ft_strlen(array)-z;
    temp = malloc(x +1);

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
    array = malloc(x+1);
    array = temp;
    return(array);
}

  
char	*ft_strjoin(char	*s1, char 	*s2)
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
	ptr[x] = '\0';
	return (ptr);
}
/* char *read_from_fd(int fd, char *buffer)
{
    ssize_t nr_bytes;
    char buf1[BUFFER_SIZE +1];
    
   
    nr_bytes = read(fd, buf1, BUFFER_SIZE);
     printf("nrbytes es : %zd\n", nr_bytes);
    if(nr_bytes == -1)
        return NULL;
    else if(nr_bytes == 0)
     return(buffer);
     buf1[nr_bytes] = '\0';
    while (nr_bytes !=0 && nr_bytes != -1)
    {    
        buffer= malloc(ft_strlen(buf1) + ft_strlen(buffer));
        buffer = ft_strjoin(buffer, buf1);
        if(checkline(buf1)==1)
            return(buffer);
        nr_bytes = read(fd, buf1, BUFFER_SIZE);
         
    }
     return (buffer);
} */
char *read_from_fd(int fd, char *buffer)
{
    ssize_t nr_bytes;
    char buf1[BUFFER_SIZE +1];
    char *temp;
     
    while(checkline(buffer)==-1 || !buffer)
    {    
    nr_bytes = read(fd, buf1, BUFFER_SIZE);
    if(nr_bytes == -1)
        return NULL;
    if(nr_bytes==0 && buffer[0]=='\0')
     {   free(buffer);
        return NULL;
     }
    else if(nr_bytes==0)
        return(buffer);
    temp = buffer;
    free(buffer);
    buf1[nr_bytes]='\0';
     
    buffer = ft_strjoin(temp, buf1);
     
    }
    return(buffer);
}
char *get_line_to_return(char *buffer)
{
    int z;
    int x;
    char *line;

    x = 0;
    z = 0;   
    while (buffer[z]!='\n' && buffer[z])         
        z++;
    
    line = malloc(z+1);

    while(x<=z)
    {
        line[x] = buffer[x];
        x++;
    }
    line[x]= '\0';
    return(line);
}
