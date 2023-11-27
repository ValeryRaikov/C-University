#include <stdio.h>

#define N 100
unsigned long mas[N];

unsigned long fib(int pos) {
    if (pos < 2)
        mas[pos] = pos;
    else if (0 == mas[pos])
        mas[pos] = fib(pos - 1) + fib(pos - 2);
    return mas[pos];
}

int main() {
    int pos;
    printf("Enter fibonacci position: ");
    scanf("%d", &pos);
    printf("Fibonacci number at position %d is: %d\n", pos, fib(pos));
    return 0;
}

