#include <stdio.h>

int main ()
{
    int n, k;
    printf("Enter the values: ");
    scanf("%d %d", &n, &k);

    int a;
    int c1=0;
    for (int i=0; i<n; i++)
    {
        printf("a= ");
        scanf("%d", &a);

        if (a>k && a%3==0)
            c1++;
    }
    printf("Count is %d", c1);

    return 0;
}
