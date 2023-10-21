#include <stdio.h>

int main() {
    int n;
    float fact = 1;

    printf("Enter number: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; ++i)
        fact *= i;

    printf("Factorial of %d is %.2f", n, fact);

    return 0;
}
