#include <stdio.h>

int main()
{
     int i, j, temp, arr[7], sum=0;

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
    for (i=0; i<6; ++i)
    {
        for (j=0; j<6-i; ++j)
        {
            if (arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("The sorted array is:\n");
    for (i=0; i<7; ++i)
        printf("%d\n", arr[i]);

    return 0;
}
