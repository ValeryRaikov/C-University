#include <stdio.h>

int sum_arr(int arr[], int length) {
    if (length == 0)
        return 0;

    return arr[0] + sum_arr(arr + 1, length - 1);
}

int main() {
    int n;
    printf("Enter number of elements to add: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element at pos[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int result = sum_arr(arr, n);
    printf("The sum of array elements is: %d", result);

    return 0;
}
