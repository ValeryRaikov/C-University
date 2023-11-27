#include <stdio.h>

int main() {
    int size;
    printf("Enter size of the array: ");
    scanf("%d", &size);
    int i, j, increment, temp, a[size];

    printf("Enter the elements of one-dimensional array\n");
    for (i = 0; i < size; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &a[i]);
    }

    increment = size - 1;
    while (increment > 0) {
        for (i = 0; i < size; i++) {
            j = i;
            temp = a[i];
            while ((j >= increment) && (a[j - increment] > temp)) {
                a[j] = a[j - increment];
                j = j - increment;
            }
            a[j] = temp;
        }
        if (increment / 2 != 0)
            increment = increment / 2;
        else if (increment == 1)
            increment = 0;
        else
            increment = 1;
    }

    printf("\nThe sorted elements of one-dimensional array\n");
    for (i = 0; i < size; i++)
        printf("arr[%d] = %d\n", i, a[i]);

    return 0;
}

