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

    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
            count++;
            while (i < n - 1 && arr[i] == arr[i + 1]) {
                i++;
            }
        }
    }

    printf("Number of equal pairs: %d\n", count);

    return 0;
}

