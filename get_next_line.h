
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

int checkline(char *array);
char *set_line(char *array);  
char *get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char *read_from_fd(int fd, char *buffer);
char *get_line_to_return(char *buffer);

#endif