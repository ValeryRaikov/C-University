#include <stdio.h>

int main()
{
    int m, n, i=1, gcd;
    printf("Enter two numbers:\n");
    scanf("%d %d", &m, &n);

    for(;i<=m && i<=n; ++i)
    {
        if(m%i==0 && n%i==0)
            gcd = i;
    }
    printf("The gcd of the numbers is %d", gcd);

    return 0;
}

