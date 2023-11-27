#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);

    int i, j, index, arr[size];

    printf("Enter the elements of one-dimensional array\n");
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    for (i = 1; i < size; i++) {
        index = arr[i];
        j = i;
        while ((j > 0) && (arr[j - 1] > index)) {
            arr[j] = arr[j - 1];
            j -= 1;
        }
        arr[j] = index;
    }

    printf("\nThe sorted elements of one-dimensional array\n");
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, arr[i]);

    return 0;
}
