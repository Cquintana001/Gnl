/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/24 13:39:41 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{	
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}
char	*ft_strdup(const char *s)
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
		while (s[x] && s[x]!= '\n')
		{
			array[x] = s[x];
			x++;
		}
		array[x] = '\0';
		return (array);
	}
}
char	*ft_strjoin(char const	*s1, char const	*s2)
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
	while (s2[j])do
    {
        /* code */
    } while (/* condition */);
    
	{
		ptr[x] = s2[j];
		x++;
		j++;
	}
	ptr[x] = '\0';
    
	return (ptr);
}

char *get_next_line(int fd)
{
     
    char *buf;
    ssize_t nr_bytes;
     
     
     
        nr_bytes = read(fd, buf, 42);
        close(fd);
         
           printf("La string devuelta es: %s", buf);  
             
             
    return(buf);     
    
 
}
int main()

{
    int fd;
     

    fd = open("/Users/caquinta/Desktop/pruebagnl.txt", O_RDONLY); 
     
       get_next_line(fd);
 

    return 0;
}