#include <stdio.h>

int main() {
    int x = 2;

    while (x <= 100) {
        x = 2 * x + 10;
    }

    printf("First x > 100 in the sequence is: %d\n", x);

    return 0;
}

