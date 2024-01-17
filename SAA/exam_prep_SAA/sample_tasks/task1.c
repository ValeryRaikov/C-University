#include <stdio.h>

int main() {
    int x0 = 2;
    int n = 0;
    int element;
    int sum = 0;

    // Намираме първият по-голям от 100 елемент
    while ((2 * x0 + 3) <= 100) {
        x0 = 2 * x0 + 3;
        n++;
    }

    // Намираме първият по-голям от 10000 елемент
    while ((2 * x0 + 3) <= 10000) {
        element = 2 * x0 + 3;

        // Проверяваме дали елементът е нечетен
        if (element % 2 != 0) {
            sum += element;
        }

        x0 = element;
        n++;
    }

    printf("The sum of odd elements between the first element greater than 100 and the first element greater than 10000 is: %d\n", sum);

    return 0;
}