/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/31 10:59:46 by caquinta         ###   ########.fr       */
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
	 
	if(fd<0 || BUFFER_SIZE <=0)
		return (NULL);
	char *line;
	static char *line2;
	/*
	if(!line2)
	{
	line2 = malloc(1);
	 
	}*/
	  
	line2 = read_from_fd(fd, line2);
	if(line2 == NULL )
	{	
		free(line2);
		return(NULL);
	}
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
	 
	fd = open("/Users/caquinta/francinette/tests/get_next_line/gnlTester/files/big_line_no_nl", O_RDWR);
	while(x<1)
	{
		result = get_next_line(fd);
		printf("%s",result);
		free(result);
		x++;
	}
	 
		 
	 
	 
	return 0;
} */
