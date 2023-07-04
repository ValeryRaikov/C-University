#include <stdio.h>

void main()
{
    int *ptr_a, *ptr_b;
    int a, b, c;
    printf("Enter 2 values:\n");
    scanf("%d %d", &a, &b);
    ptr_a = &a;
    ptr_b = &b;

    printf("Value of a is %d\n", *ptr_a);
    printf("Value of b is %d\n", *ptr_b);
    printf("Address of a is %x\n", ptr_a);
    printf("Address of  is %x\n", ptr_b);

    int *ptr_c;
    if(*ptr_a > *ptr_b)
        ptr_c = &a;
    else
        *ptr_c = &b;
    printf("%d", *ptr_c);

    int numbers[5] = {1,2,3,4,5};
    int *ptr_nums;
    ptr_nums = &numbers[5];

    for(int i=0; i<5; ++i)
    {
        printf("%d", *(ptr_nums+i));
    }
}
