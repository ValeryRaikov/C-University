#include <stdio.h>

int fib(int pos) {
    if (pos <= 0)
        return 0;
    else if (pos == 1)
        return 1;

    int prev = 0;
    int current = 1;
    int result;

    for (int i = 2; i <= pos; ++i) {
        result = prev + current;
        prev = current;
        current = result;
    }

    return result;
}

int main() {
    int pos;
    printf("Enter fibonacci position: ");
    scanf("%d", &pos);
    printf("Fibonacci number at position %d is: %d\n", pos, fib(pos));

    return 0;
}

