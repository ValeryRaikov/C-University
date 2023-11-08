#include <stdio.h>

void reverse(int n) {
    if (n < 10)
        printf("%d", n);
    else {
        printf("%d", n % 10);
        reverse(n / 10);
    }
}

int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);

    printf("Reversed number is: ");
    reverse(num);

    return 0;
}

