#include <stdio.h>

int main()
{
    FILE *fptr = fopen("Fgetc.txt", "r");
    if (fptr == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    char value;

    /*while ((value = fgetc(fptr)) != EOF)
    {
        printf("%c", value);
    }*/

    //store text in a buffer:
    char buff[256];
    int i=0;
    while ((value = fgetc(fptr)) != EOF)
    {
        buff[i] = value;
        i++;
    }
    printf("Buffer:\n%s", buff);

    return 0;
}
