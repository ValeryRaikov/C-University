#include <stdio.h>

int main() {
    int a, b;

    printf("a =  ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);

    a = a * b;
    b = a / b;
    a = a / b;

    printf("a after change: %d\n", a);
    printf("b after change: %d\n", b);

    return 0;
}

