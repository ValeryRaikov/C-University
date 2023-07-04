#include <stdio.h>

void swap_nums(int*, int*);

void main ()
{
    int num1, num2;
    printf("Enter values for num1 and num2:\n");
    scanf("%d %d", &num1, &num2);
    printf("You entered: a=%d, b=%d\n", num1, num2);
    swap_nums(&num1, &num2);
    printf("Result: a=%d, b=%d",num1, num2);
}
void swap_nums(int* a, int* b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
