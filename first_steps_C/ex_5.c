#include <stdio.h>

int main ()
{
    int n, sum;
    while (1)
    {
        printf("number= ");
        scanf("%d", &n);

        if (n==0)
            break;

        sum += n;
    }
    printf("Sum is %d", sum);
    return 0;
}

