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
 
int main()
{
    int check;
    char array[42] = "HOLA\nHola\nadios\n";
    int x = 0;
    while (checkline(array))
    {
        //printf("entraaaa\n");

        check = checkline(array);
        printf("El valor de check es: %d\n", check);

        setline(array, check);

        printf("El valor del nuevo array  es: %s\n", array);
        x++;
    }
    return (0);
}