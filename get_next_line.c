/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/29 17:41:31 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "get_next_line.h"
#include <limits.h>
 
char *get_next_line(int fd)
{
	 
	char *line;
	static char *line2;
	
	line2 = malloc(1);
	line2[0] = '\0';
	if(!fd || fd == -1 || BUFFER_SIZE <=0)
		return (NULL);
	  
	line2 = read_from_fd(fd, line2);
	if(!line2)
		return(NULL);
	else
	{
		line = get_line_to_return(line2);
		line2 = set_line(line2);
		return(line);
	}
}
/* int main()

{
	int fd;
	 
	int x;
	char *result;

	x = 0;
	 
	fd = open("/Users/caquinta/Desktop/pruebagnl.txt", O_RDWR);
	  
		result = get_next_line(fd);
		printf("linea %d es %s",x,  result);
		if (result)
			free(result);
		 
	 
	 
	return 0;
} */