#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size;
    printf("Enter the size:\n");
    scanf("%d", &size);
    int *matrix;
    int i, j = 0;
    int sum = 0, sum1 = 0, sum2 = 0;
    int flag = 0;

    matrix = malloc((size*size) * sizeof(int));
    if (matrix == NULL)
    {
        exit(EXIT_FAILURE);
    }

    printf("\nEnter matrix:\n");
    for (int i = 0; i < (size*size); ++i)
    {
        scanf("%d", &matrix[i]);
    }

    printf("Entered matrix is:\n");
    int counter = 0;
    for (int i = 0; i < (size*size); ++i)
    {
        printf("%d ", matrix[i]);
        counter ++;
        if (counter % size == 0)
            putchar('\n');
    }

    for (int i = 0; i < (size*size); ++i)
    {
        if (i == j)
            sum += matrix[i];
    }

    for (int i = 0; i < (size*size); ++i)
    {
        sum1 = 0;
        sum1 += matrix[i];
        if (sum == sum1)
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }

    for (int i = 0; i < (size*size); ++i)
    {
        sum2 = 0;
        sum2 += matrix[j];
         if (sum == sum2)
            flag = 1;
        else
        {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("\nMagic square");
    else
        printf("\nNo Magic square");

    free(matrix);

    return 0;
}
