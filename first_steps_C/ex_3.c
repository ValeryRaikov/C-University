#include <stdio.h>
int main ()
{
    int a, b;
    printf("Enter the numbers: ");
    scanf("%d %d", &a, &b);
    printf("a=%d, b=%d\n", a, b);

    int sum = 0, mult = 1;
    for (int i=a+1; i<b; i++)
    {
        if (i%2==0) {
            sum += i;
        } else
            mult *= i;
    }
    printf("The sum is %d\n", sum);
    printf("The mult is %d\n", mult);

    return 0;
}

