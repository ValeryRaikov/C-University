#include <stdio.h>

int power(int n, int k) {
    if (n <= 1)
        return n;

    if (k == 0)
        return 1;

    if (k == 1)
        return n;

    int pow = 1;
    for (int i=0; i<k; i++)
        pow *= n;

    return pow;
}

int main() {
    int n, k;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Enter power: ");
    scanf("%d", &k);

    printf("%d^%d = %d", n, k, power(n, k));

    return 0;
}