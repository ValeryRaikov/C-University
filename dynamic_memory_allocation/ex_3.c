#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr;
    int i, sum=0;

    arr = (int*)malloc(7 * sizeof(int));
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
        sum+=arr[i];
        ++i;
    }
    float average = (float)sum/7;
    printf("Average sum is %.2f\n", average);

    free(arr);

    return 0;
}
