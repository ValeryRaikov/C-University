#include <stdio.h>

long long sum = 0;
void sum1toN(int n) {
    if (n < 1)
        return;

    sum1toN(n - 1);
    sum += n;
}

int main(void) {
    // If using too big numbers the program will crash...
    int number;
    printf("Enter final number: ");
    scanf("%d", &number);

    sum1toN(number);
    printf("Total sum from 1 to %d is: %lld\n", number, sum);
    return 0;
}