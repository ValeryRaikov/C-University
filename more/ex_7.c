#include <stdio.h>

int fibonacci(int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    else
        return(fibonacci(n-1) + fibonacci(n-2));
}

int main()
{
    int n, i=0, c;
    printf("Enter the length:\n");
    scanf("%d", &n);
    printf("Fibonacci series:\n");

    for(c=1; c<=n; ++c)
    {
        int res = fibonacci(i);
        printf("%d ", res);
        i++;
    }

    return 0;
}
