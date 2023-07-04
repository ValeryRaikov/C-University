#include <stdio.h>
#include <stdlib.h>

#define NMEMB 1

int create_write_to_file();

int main()
{
    create_write_to_file();

    return 0;
}

int create_write_to_file()
{
    FILE *fptr = fopen("fwrite_operations.txt", "w");
    if (fptr == NULL)
    {
        perror("Error opening file!");
        return 1;
    }
    int number_of_chars;
    printf("Enter number of characters to display: ");
    do
    {
        scanf("%d", &number_of_chars);
    } while (number_of_chars <= 0);

    char *buffer = (char*)malloc(number_of_chars * sizeof(char));
    printf("Enter your text: ");
    fflush(stdin);
    if (fgets(buffer, sizeof(buffer), stdin)==NULL)
    {
        perror("Input error!");
        return 1;
    }

    if (fwrite(buffer, sizeof(buffer), NMEMB, fptr)!=NMEMB)
    {
        perror("Writing error!");
        return 1;
    }
    fclose(fptr);

    return 0;
}
