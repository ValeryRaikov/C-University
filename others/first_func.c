#include <stdio.h>

void add(int num1, int num2)
{
    int addition = num1 + num2;
    printf("%d + %d = %d", num1, num2, addition);
}

int square(int number)
{
     int square = number * number;
     return square;
}

int main()
{
    add(5, 10);

    int result = square(5);
    printf("Square is %d", result);

    return 0;
}
