#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>

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
char *get_next_line(int fd)
{

	char *line;
	// static char line2[1024][BUFFER_SIZE + 1];
	static char *line2[1024]; // OPEN_MAX .h???
	char buf[BUFFER_SIZE + 1];
	int x;
	int y;
	int z;
	int check;
	ssize_t nr_bytes;
	char *temp;
	
    if (!line2[fd])
        line2[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	x = 0;
	y = 0;
	z = 0;
	check = checkline(line2[fd]);
	printf("check = %d\n", check);
	line = malloc(300);
	if(check!=0) 
    {
		while(x<=check)
		{
			line[x] = line2[fd][x];
			x++;
		}
		line[x] ='\0';
        setline(line2[fd], check); //<= AQUÍ ESTA EL PROBLEMA!!!!!!
        return(line);
    }
    else
	  y = cpline(line2[fd], line);

	while (line[y] != '\n')
	{
		x = 0;
		nr_bytes = read(fd, buf, BUFFER_SIZE);
		if(nr_bytes==0)
			return(line);
		buf[nr_bytes] = '\0';
		while (buf[x])
		{
			if (buf[x] == '\n')
			{
				line[y] = '\n';
				 
				x++;
				 
				while (buf[x])
				{
					line2[fd][z] = buf[x];
					x++;
					z++;
				}
				line2[fd][z] = '\0';
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
	printf("Lo que sobra es: %s\n", line2[fd]);
	return (line);
}

/* int main()
{
	int fd;
	ssize_t nr_bytes;
	int x;
	char *result;

	x = 0;

	fd = open("/Users/caquinta/Desktop/pruebagnl.txt", O_RDONLY);
	 while(x<5)
	 {
		result = get_next_line(fd);
		printf("linea %d es %s",x,  result);
		free(result);
		x++;
	 }
	
	close(fd);
	return 0;
} */