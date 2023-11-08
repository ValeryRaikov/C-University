#include <stdio.h>

int fact(int n) {
    int fact = 1;

    if (n <= 1)
        return fact;
    else {
        for (int i = 1; i <= n; i++) {
            fact *= i;
        }
        return fact;
    }
}

int main() {
    int num;
    printf("Enter a number to find factorial: ");
    scanf("%d", &num);

    int result = fact(num);
    printf("Factorial of %d is %d", num, result);

    return 0;
}
