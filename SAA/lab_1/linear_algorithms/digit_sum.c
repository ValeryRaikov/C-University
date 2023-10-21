#include <stdio.h>

int main() {
    int number, units, tens, hundreds, sum;

    printf("Enter a three digit number: ");
    scanf("%d", &number);

    while (1) {
    if (number >= 100 && number <= 999) {
        units = number % 10;
        tens = (number / 10) % 10;
        hundreds = number / 100;
        break;
    } else {
        printf("Mistake in number! Enter again: ");
        scanf("%d", &number);
        }
    }

    sum = units + tens + hundreds;

    printf("Digit sum is: %d\n", sum);

    return 0;
}
