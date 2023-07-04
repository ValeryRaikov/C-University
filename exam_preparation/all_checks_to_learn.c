#include <stdio.h>
#include <stdlib.h>

#define NMEMB 1

int main()
{
    //fgets error check:
    char name[20];
    if (fgets(name, sizeof(name), stdin)==NULL)
    {
        printf("Fgets error!");
        return 1;
    }
    fflush(stdin);

    //dynamic memory error check:
    int *grades = calloc(5, sizeof(int));
    if (grades == NULL)
    {
        printf("Dynamic memory error!");
        return 1;
    }
    free(grades);

    //file error check:
    FILE *fptr = fopen("Test_file.txt", "w");
    if (fptr == NULL)
    {
        printf("File opening error!");
        return 1;
    }

    //fclose error check:
    if (fclose(fptr)==0)
    {
        printf("File closure error!");
        return 1;
    }

    //fprintf error check:
    if (fprintf(fptr, "%s %d %c", "Valery", 19, 'M') < 0)
    {
        printf("fprintf error!");
        return 1;
    }

    //fwrite error check:
    char buff[10] = "Test code";
    if (fwrite(buff, sizeof(buff), NMEMB, fptr) != NMEMB)
    {
        printf("fwrite error!");
        return 1;
    }

    //fread error check:
    char buff2[10];
    if (fread(buff2, sizeof(buff2), NMEMB, fptr) != NMEMB)
    {
        printf("fread error!");
        return 1;
    }

    return 0;
}
