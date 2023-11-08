#include <stdio.h>

int recursive_sum(int arr[], int index, int length) {
    if (index >= length)
        return 0;

    int currentElement = arr[index];
    int nextSum = recursive_sum(arr, index + 1, length);

    return currentElement + nextSum;
}

int main() {
    int n;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = recursive_sum(arr, 0, n);
    printf("Sum of array elements: %d\n", sum);

    return 0;
}
