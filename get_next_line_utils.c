/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 17:32:15 by caquinta          #+#    #+#             */
/*   Updated: 2022/05/27 11:18:40 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include "get_next_line.h"

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
void setline(char *array, int index) // trim the string until reach the index
{
    int z;
    char temp[42];

    z = 0;
    index++;
    while (array[index])
    {
        temp[z] = array[index];
        z++;
        index++;
    }
    temp[z] = '\0';
    z = 0;
    while (temp[z])
    {
        array[z] = temp[z];
        z++;
    }
    array[z] = '\0';
}

int cpline(char *temp, char *array)
{
    int x;
     
    x=0;
    while(temp[x])
    {
        array[x] = temp[x];
        x++;
    }
    array[x]='\0';
     return(x);
}