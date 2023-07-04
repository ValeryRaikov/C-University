#include <stdio.h>

int my_func(int, int);

void main ()
{
    int num1, num2, result;
    printf("Enter numbers:\n");
    scanf("%d %d", &num1, &num2);

    result = my_func(num1, num2);
    printf("Result = %d", result);
}

int my_func(int a, int b)
{
    return a + b;
}

