#include <stdio.h>

int fib(int k) {
    if (k <= 1) {
        return k;
    }

    return fib(k-1) + fib(k-2);
}

int main() {
    int pos;
    printf("Enter a position to find the value of a fibonacci sequence: ");
    scanf("%d", &pos);

    int result = fib(pos);
    printf("Fiboncci value at position %d is: %d", pos, result);

    return 0;
}