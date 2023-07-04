#include <stdio.h>
#include <stdlib.h>

int main()
{
    char buffer[100];

    FILE *fp;
    fp = fopen("cars_file_read.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening the file.");
        exit(1);
    }
    fseek(fp, 0, SEEK_SET);

    fread(buffer, 100, 1, fp);
    printf("%s\n", buffer);

    fclose(fp);

    return 0;
}
