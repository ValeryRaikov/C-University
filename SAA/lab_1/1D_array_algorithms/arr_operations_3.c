#include <stdio.h>

int main() {
    int n;
    printf("Enter arr length: ");
    scanf("%d", &n);

    while (1) {
        if (n < 2) {
            printf("n must be greater than 2! Try again: ");
            scanf("%d", &n);
        } else
            break;
    }

    int arr[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int product = 1;

    for (int i = 0; i < n - 1; ++i) {
        int sum = arr[i] + arr[i + 1];
        if (sum <= 120) {
            product *= arr[i];
        }
    }

    printf("Multiplication of elements with sum <= 120 is: %d\n", product);

    return 0;
}

