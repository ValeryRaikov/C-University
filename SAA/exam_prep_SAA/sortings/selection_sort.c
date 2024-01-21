#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int i, j, arr[size], min, imin;

    printf("Enter the elements of one-dimensional array\n");
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < size - 1; i++) {
        min = arr[i];
        imin = i;
        for (j = i+1; j < size; j++) {
            if (min > arr[j]) {
                min = arr[j];
                imin = j;
            }
        }
        arr[imin] = arr[i];
        arr[i] = min;
    }

    printf("\nThe sorted elements of one-dimensional array\n");
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0;
}