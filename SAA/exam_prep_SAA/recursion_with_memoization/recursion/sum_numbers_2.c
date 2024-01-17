#include <stdio.h>

long long sum1toN(int n) {
    if (n < 1)
        return 0;

    return n + sum1toN(n - 1);
}

int main(void) {
    printf("The sum is: %lld\n", sum1toN(10000));
    return 0;
}