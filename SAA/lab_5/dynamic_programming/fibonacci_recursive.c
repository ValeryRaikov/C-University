#include <stdio.h>

int fib(int pos) {
    if (pos <= 0)
        return 0;
    else if (pos == 1)
        return 1;
    else
        return fib(pos-1) + fib(pos-2);
}

int main() {
    int pos;
    printf("Enter fibonacci position: ");
    scanf("%d", &pos);
    printf("Fibonacci number at position %d is: %d", pos, fib(pos));

    return 0;
}
