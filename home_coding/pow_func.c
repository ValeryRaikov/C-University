#include <stdio.h>

int power(int, int);

int main()
{
    int num, pow;
    printf("Enter number and power:\n");
    scanf("%d %d", &num, &pow);

    int result = power(num, pow);
    printf("%d^%d=%d", num, pow, result);

    return 0;
}

int power(int base, int n)
{
    int number=1;
    for(int i=0; i<n; ++i)
    {
        number *= base;
    }
    return number;
}
