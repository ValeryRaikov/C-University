#include <stdio.h>
int main ()
{
    int a, b;
    printf("Enter the numbers: ");
    scanf("%d %d", &a, &b);
    printf("a=%d, b=%d\n", a, b);

    int sum=0;
    for (int i=a+1; i<b; i++)
    {
        sum += i;
    }
    printf("The sum is %d", sum);

    return 0;
}
