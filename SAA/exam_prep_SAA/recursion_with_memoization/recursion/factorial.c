#include <stdio.h>

int fact(int n) {
    if (n <= 1) {
        return 1;
    }

    return n * fact(n-1);
}

int main() {
    int number;
    printf("Enter number to find factorial: ");
    scanf("%d", &number);

    int result = fact(number);
    printf("The factorial of %d is: %d", number, result);

    return 0;
}