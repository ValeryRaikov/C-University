#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements to store in your array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i=0; i<n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (int i=n-1; i>=0; i--) {
        for (int j=1; j<=i; j++) {
            if (arr[j-1] > arr[j]) {
                int temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array using bubble sort method:\n");
    for (int i=0; i<n; i++) {
        printf("a[%d] = %d\n", i, arr[i]);
    }

    return 0;
}