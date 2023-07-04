#include <stdio.h>

int main()
{
    int arr[] = {1,4,9,7,3,6};
    int *ptr = arr;
    int size = sizeof(arr) / sizeof(arr[0]);

    for(int i=0; i<size; ++i)
    {
        printf("Value of %d element is: %d\n", i, *(ptr+i));
        printf("Value of %d element is: %d\n", i, ptr[i]);
    }

    return 0;
}
