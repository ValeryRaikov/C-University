#include <stdio.h>
#include <stdbool.h>

bool contains_digit(int n, int digit) {
    if (n == 0)
        return false;

    if (n % 10 == digit) {
        return true;
    }

    return contains_digit(n / 10, digit);
}

int main() {
    int number, digit;

    printf("Enter a natural number: ");
    scanf("%d", &number);

    printf("Enter the digit to check for: ");
    scanf("%d", &digit);

    if (contains_digit(number, digit)) {
        printf("%d contains the digit %d.\n", number, digit);
    } else {
        printf("%d does not contain the digit %d.\n", number, digit);
    }

    return 0;
}

