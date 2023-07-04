#include <stdio.h>

int main ()
{
    int a, b, c;
    printf("Enter the numbers:\n");
    scanf("%d %d %d", &a, &b, &c);

    if (a==b && b==c)
        printf("Yes");
    else
        printf("No");

    return 0;
}
