#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fptr = fopen("fprintf_operations.txt", "w");
    if (fptr == NULL)
    {
        perror("Error opening file!");
        return 1;
    }

    char message[150];
    printf("Enter your bio: ");
    if (fgets(message, sizeof(message), stdin)==NULL)
    {
        perror("Input error!");
        return 1;
    }

    if (fprintf(fptr, "%s", message)<0)
    {
        perror("Writing error!");
        return 1;
    }

    int total_subjects;
    printf("Enter the number of subjects you study: ");
    do
    {
        scanf("%d", &total_subjects);
    } while (total_subjects <= 0);

    int *grades = (int*)malloc(total_subjects * sizeof(int));
    if (grades == NULL)
    {
        perror("Dynamic memory error!");
        return 1;
    }

    printf("Enter your grades:\n");
    for (int i=0; i<total_subjects; ++i)
    {
        do
        {
            scanf("%d", &grades[i]);
        } while (grades[i] < 2 || grades[i] > 6);
    }

    fprintf(fptr, "Grades:\n");
    for (int i=0; i<total_subjects; ++i)
    {
        if (fprintf(fptr, "%d ", grades[i])<0)
        {
            perror("Writing error!");
            return 1;
        }
    }

    fclose(fptr);
    free(grades);

    return 0;
}
