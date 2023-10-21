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
        scanf(" %d", &arr[i]);
    }

    int count = 0;

    for (int i = 0; i < n - 1; ++i) {
        if ((arr[i] < 0 && arr[i + 1] > 0) || (arr[i] > 0 && arr[i + 1] < 0)) {
            count++;
        }
    }

    printf("Pair of numbers with opposite signs is: %d\n", count);

    return 0;
}

