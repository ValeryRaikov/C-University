#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int i, j, temp, arr[size];

    printf("Enter the elements of one-dimensional array\n");
    for (i = 0; i < size; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (i = size - 1; i >= 0; i--) {
        for (j = 1; j <= i; j++) {
            if (arr[j - 1] > arr[j]) {
                temp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("\nThe sorted elements of one-dimensional array\n");
    for (i = 0; i < size; i++)
        printf("a[%d] = %d\n", i, arr[i]);

    return 0;
}

