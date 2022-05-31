/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caquinta <caquinta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 11:27:29 by user              #+#    #+#             */
/*   Updated: 2022/04/10 10:53:09 by caquinta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);

/*void	ft_print_result(char const *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int	main(void)
{
	char	str[];
	char	*str_dup;
	char	*array;
	int		x;
	char	*array;
	int		x;

	str[] = "lorem ipsum dolor sit amet";
		
		if (!(str_dup = ft_strdup(str)))
			ft_print_result("NULL");
		else
			ft_print_result(str_dup);
		if (str_dup == str)
			ft_print_result("\nstr_dup's adress == str's adress");
	
	return (0);
}*/
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
		while (s[x])
		{
			array[x] = s[x];
			x++;
		}
		array[x] = '\0';
		return (array);
	}
}
