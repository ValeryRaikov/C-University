#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter integer values for 3 numbers:\n");

    printf("a = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    printf("c = ");
    scanf("%d", &c);

    if (a < b)
        if (b < c)
            printf("%d<%d<%d", a, b, c);
        else if (a < c)
            printf("%d<%d<%d", a, c, b);
        else
            printf("%d<%d<%d", c, a, b);
    else if (b < c)
        if (a < c)
            printf("%d<%d<%d", b, a, c);
        else
            printf("%d<%d<%d", b, c, a);
    else
        printf("%d<%d<%d", c, b, a);

    return 0;
}