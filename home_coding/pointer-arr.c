#include <stdio.h>

void main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Via array:\n");
    for(int i=0; i<5; ++i)
        printf("%d\n", *(arr+i));

    printf("Via ptr:\n");
    for(int i=0; i<5; ++i)
        printf("%d\n", ptr[i]);
}
