#include <stdio.h>

int main() {
    int n;
    printf("Enter arr length: ");
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; ++i) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    int max = arr[0];
    int sum = 0;
    int oddCount = 0;
    int containsN = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }

        sum += arr[i];

        if (arr[i] % 2 != 0) {
            oddCount++;
        }

        if (arr[i] < 0 && arr[i] == -n) {
            containsN = 1;
        }
    }

    double average = (double)sum / n;

    printf("Max value: %d\n", max);
    printf("Avg value: %.2f\n", average);
    printf("Odd elements count: %d\n", oddCount);

    if (containsN) {
        printf("n is present in the negative elements.\n");
    } else {
        printf("n is not present in the negative elements.\n");
    }

    return 0;
}

