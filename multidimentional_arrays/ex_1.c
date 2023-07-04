#include <stdio.h>

void main()
{
    int N;
    printf("Enter size:\n");
    scanf("%d", &N);
    int array[N][N];
    int i, j;
    printf("Enter the elements:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    printf("The matrix looks like this:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("Main diagonal:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", array[i][i]);
    }
    printf("\n");
    printf("Minor diagonal:\n");
    for (i = 0; i < N; i++)
    {
        printf("%d ", array[i][N - i - 1]);
    }
    printf("\n");
    printf("Elements above the main diagonal:\n");
    for (i = 0; i < N; i++)
    {
        for (j = i + 1; j < N; j++)
        {
            printf("%d ", array[i][j]);
        }
    }
    printf("\n");
    printf("Elements below the main diagonal:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < i; j++)
        {
            printf("%d ", array[i][j]);
        }
    }

}
