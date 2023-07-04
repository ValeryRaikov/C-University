#include <stdio.h>
#include <stdlib.h>

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

    int closest_num = arr[0];
    int closest_idx = 0;
    int min_diff = abs(arr[0] - average);

    for (i=1; i<7; ++i)
    {
        int diff = abs(arr[i] - average);
        if (diff<min_diff)
        {
            closest_num = arr[i];
            closest_idx = i;
            min_diff = diff;
        }
    }
    printf("The average value is %.2f, the closest number is %d, the closest index is %d\n", average, closest_num, closest_idx);

    return 0;
}
