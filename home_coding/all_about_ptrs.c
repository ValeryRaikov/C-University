#include <stdio.h>

int main()
{
    int arr[] = {10,20,30,40,50};
    int *ptr = arr;

    for(int i=0; i<5; ++i)
    {
        //All possible ways to display value:
        printf("(1) %d\n", arr[i]);
        printf("(2) %d\n", *(arr+i));
        printf("(3) %d\n", ptr[i]);
        printf("(4) %d\n", *(ptr+i));
        putchar('\n');
    }

    for(int i=0; i<5; ++i)
    {
        //All possible ways to display memory allocation:
        printf("(1) %p\n", &arr[i]);
        printf("(2) %p\n", (arr+i));
        printf("(3) %p\n", &ptr[i]);
        printf("(4) %p\n", (ptr+i));
        putchar('\n');
    }
    //Change array values:
    arr[0] = 60;
    *(arr+1) = 70;
    ptr[2] = 80;
    *(ptr+3) = 90;
    for(int i=0; i<5; ++i)
        printf("%d\n", arr[i]);

    return 0;
}
