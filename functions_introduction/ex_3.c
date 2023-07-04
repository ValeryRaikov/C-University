#include <stdio.h>

int check(int*);

void main()
{
    int num;
    printf("Enter number:\n");
    scanf("%d", &num);
    check_num(&num);
}
void check_num(int* a)
{
    int* ptr;
    ptr = &a;
    if (*ptr % 2 == 0)
        printf("Even");
    else
        printf("Uneven");
}
