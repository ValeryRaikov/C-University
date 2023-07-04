#include <stdio.h>

int main()
{
    int nums[5];
    printf("Create your array:\n");
    for(int i=0; i<5; ++i)
    {
        scanf("%d", &nums[i]);
        if(nums[i] < -100 || nums[i] > 100)
        {
            printf("Number out of range!\n");
            continue;
        }
    }
    int *ptr;
    ptr = &nums[0];
    for(int i=0; i<5; ++i)
        printf("Value->%d, Address->%p\n", *(ptr+i), ptr+i);

    return 0;
}
