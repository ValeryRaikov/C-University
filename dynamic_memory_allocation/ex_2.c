#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, max;

    arr = (int*)calloc(7, sizeof(int));
    if (arr == NULL)
    {
       exit(EXIT_FAILURE);
    }

    printf("Enter 7 numbers\n");
    while (i<7)
    {
        scanf("%d", &arr[i]);
        if (arr[i] < -5000 || arr[i] > 5000)
        {
            printf("Number out of range!\n");
            continue;
        }
        ++i;
    }
    max = arr[0];
    for (i=1; i<7; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    printf("The biggest number is %d\n", max);

    free(arr);

    return 0;
}

