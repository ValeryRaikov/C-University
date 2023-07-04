#include <stdio.h>

int main()
{
    int i, arr[7], sum=0;

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

    return 0;
}
