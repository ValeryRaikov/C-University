#include <stdio.h>

int F[51];

int fib(int n) {
    if (F[n] != -1) {
        return F[n];
    }

    F[n] = fib(n - 1) + fib(n - 2);
    return F[n];
}

int main() {
    for (int i=0; i<51; i++) {
        F[i] = -1;
    }

    F[0] = 0;
    F[1] = 1;

    int n;
    printf("Enter a whole number: ");
    scanf("%d", &n);

    int result = fib(n);

    printf("Result is %d\n", result);

    return 0;
}