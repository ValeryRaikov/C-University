#include <stdio.h>
#include <stdlib.h>

int min(int num1, int num2) {
    if (num1 < num2)
        return num1;
    else
        return num2;
}

int nod(int num1, int num2) {
    if (num1 == 0 || num2 == 0)
        return 0;
    else if (num1 == num2)
        return num1;
    else
        return nod(abs(num1 - num2), min(num1, num2));
}

int main() {
    int num1, num2;
    printf("num1 = ");
    scanf("%d", &num1);
    printf("num2 = ");
    scanf("%d", &num2);

    printf("Nai-malyk obsht delitel = %d\n", nod(num1, num2));

    return 0;
}
