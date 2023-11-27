#include <stdio.h>
#include <stdlib.h>

int min(int num1, int num2) {
    if (num1 < num2)
        return num1;
    else
        return num2;
}

int gcd(int num1, int num2) {
    if (num2 == 0)
        return 0;
    else
        return gcd(num2, num1 % num2);
}

int main() {
    int num1, num2;
    printf("num1 = ");
    scanf("%d", &num1);
    printf("num2 = ");
    scanf("%d", &num2);

    printf("Nai-golqm obsht delitel = %d\n", gcd(num1, num2));

    return 0;
}
